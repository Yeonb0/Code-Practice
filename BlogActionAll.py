import os
import re
from datetime import datetime
from github import Github
from convert import convert_to_markdown

GITHUB_TOKEN = os.environ["BLOG_TOKEN"]
REPO_NAME = "Yeonb0/Code-Practice"
BASE_PATH = "백준"
OUTPUT_DIR = "generated"

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

  tiers = repo.get_contents(BASE_PATH)
  for tier in tiers:
    if tier.type != "dir":
      continue

    tier_name = tier.name              # 예: "Bronze 1"
    tier_category = tier_name.split()[0]  # 예: "Bronze"

    problems = repo.get_contents(tier.path)
    for p in problems:
      if p.type != "dir":
        continue

      num, title = p.name.split(".", 1)
      files = repo.get_contents(p.path)

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
