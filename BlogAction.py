import os
import re
from datetime import datetime
from github import Github
from convert import convert_to_markdown

GITHUB_TOKEN = os.environ["BLOG_TOKEN"]
REPO_NAME = "Yeonb0/Code-Practice"

OUTPUT_DIR = "_posts/BOJ"
os.makedirs(OUTPUT_DIR, exist_ok=True)

def extract_tags(readme: str):
  tags = set()
  m = re.search(r"### 분류\s+(.*)", readme)
  if m:
    raw = m.group(1).split("\n")[0]
    for t in raw.split(","):
      if t.strip():
        tags.add(t.strip())
  tags.add("C++")
  return sorted(tags)

def main():
  g = Github(GITHUB_TOKEN)
  repo = g.get_repo(REPO_NAME)
  today = datetime.now().strftime("%Y-%m-%d")

  # 🔑 이번 커밋에서 변경된 파일만 사용
  with open("changed.txt", encoding="utf-8") as f:
    changed = f.readlines()

  processed = set()

  for line in changed:
    path = line.strip()

    # BOJ 문제 파일만
    if not path.startswith("백준/"):
      continue

    # 문제 폴더 경로 추출
    folder = "/".join(path.split("/")[:-1])
    if folder in processed:
      continue
    processed.add(folder)

    # 폴더명에서 번호/제목 추출
    name = folder.split("/")[-1]
    if "." not in name:
      continue

    num, title = name.split(".", 1)

    files = repo.get_contents(folder)

    readme = None
    code = None
    for f in files:
      if f.name == "README.md":
        readme = f.decoded_content.decode("utf-8")
      elif f.name.endswith(".cc"):
        code = f.decoded_content.decode("utf-8")

    if not readme or not code:
      continue

    # 티어 정보
    tier_name = folder.split("/")[1]           # Bronze 1
    tier_category = tier_name.split()[0]       # Bronze

    tags = extract_tags(readme)

    front = "---\n"
    front += "layout: single\n"
    front += f"title: \"[{tier_name} / {num}] {title.strip()}\"\n"
    front += "categories:\n"
    front += "  - BOJ\n"
    front += f"  - {tier_category}\n"
    front += "tags:\n"
    for t in tags:
      front += f"  - {t}\n"
    front += "---\n\n"

    body = convert_to_markdown(readme)
    body += "\n\n## 💻 코드 (C++)\n\n"
    body += "```cpp\n"
    body += code.rstrip() + "\n"
    body += "```\n\n"

    fname = f"{today}-boj-{num}.md"
    out_path = os.path.join(OUTPUT_DIR, fname)

    # 혹시 같은 날 재실행 방지
    if os.path.exists(out_path):
      continue

    with open(out_path, "w", encoding="utf-8") as out:
      out.write(front + body)

    print("[생성 완료]", fname)

if __name__ == "__main__":
  main()
