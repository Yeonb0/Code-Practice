import os
import re
from datetime import datetime
from github import Github
from convert import convert_to_markdown

GITHUB_TOKEN = os.environ["BLOG_TOKEN"]
REPO_NAME = "Yeonb0/Code-Practice"
OUTPUT_DIR = "_posts/BOJ"

os.makedirs(OUTPUT_DIR, exist_ok=True)

def extract_tags(readme):
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

  with open("changed.txt", encoding="utf-8") as f:
    changed = f.readlines()

  done = set()

  for line in changed:
    if not line.startswith("백준/"):
      continue

    parts = line.strip().split("/")
    tier_name = parts[1]                 # "Bronze 1"
    tier_category = tier_name.split()[0] # "Bronze"

    num = None
    title = None
    for p in parts:
      if "." in p:
        num, title = p.split(".", 1)
        break

    if not num or num in done:
      continue
    done.add(num)

    folder = "/".join(parts[:-1])
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
    with open(os.path.join(OUTPUT_DIR, fname), "w", encoding="utf-8") as out:
      out.write(front + body)

    print("[생성 완료]", fname)

if __name__ == "__main__":
  main()
