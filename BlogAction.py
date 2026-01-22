import os
import re
import codecs
from datetime import datetime
from convert import convert_to_markdown

OUTPUT_DIR = "_posts/BOJ"
os.makedirs(OUTPUT_DIR, exist_ok=True)


def normalize_path(raw: str) -> str:
  raw = raw.strip()

  # 앞뒤 따옴표 제거
  if raw.startswith('"') and raw.endswith('"'):
    raw = raw[1:-1]

  try:
    # 1단계: \353\260... 같은 escape 해제
    s = codecs.decode(raw, "unicode_escape")

    # 2단계: 깨진 문자열을 다시 bytes로 보고
    # 3단계: UTF-8로 재해석
    raw = s.encode("latin1").decode("utf-8")
  except Exception as e:
    print("[WARN] normalize failed:", raw, e)

  return raw


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
  today = datetime.now().strftime("%Y-%m-%d")

  # 🔑 이번 커밋에서 변경된 파일 목록
  with open("changed.txt", encoding="utf-8") as f:
    changed = [normalize_path(line) for line in f if line.strip()]

  processed = set()

  for path in changed:
    print("[DEBUG] normalized path:", path)

    # BOJ 경로만 처리
    if not path.startswith("백준/"):
      continue

    # 문제 폴더 추출
    folder = os.path.dirname(path)
    if folder in processed:
      continue
    processed.add(folder)

    print("[DEBUG] folder:", folder)

    # 폴더명에서 번호 / 제목 추출
    name = os.path.basename(folder)
    if "." not in name:
      continue

    num, title = name.split(".", 1)

    if not os.path.isdir(folder):
      print("[DEBUG] folder not found:", folder)
      continue

    readme = None
    code = None

    # 🔑 로컬 파일 기준으로 README / 코드 탐색
    for fname in os.listdir(folder):
      full = os.path.join(folder, fname)

      if fname == "README.md":
        with open(full, encoding="utf-8") as f:
          readme = f.read()

      elif fname.endswith((".cc", ".cpp", ".cxx")):
        with open(full, encoding="utf-8") as f:
          code = f.read()

    print("[DEBUG] readme:", bool(readme), "code:", bool(code))

    if not readme or not code:
      continue

    # 티어 정보
    parts = folder.split("/")
    tier_name = parts[1]                  # Gold
    tier_category = tier_name.split()[0]  # Gold

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
    body += "```\n"

    fname = f"{today}-boj-{num}.md"
    out_path = os.path.join(OUTPUT_DIR, fname)

    if os.path.exists(out_path):
      print("[SKIP] already exists:", fname)
      continue

    with open(out_path, "w", encoding="utf-8") as out:
      out.write(front + body)

    print("[생성 완료]", fname)


if __name__ == "__main__":
  main()
