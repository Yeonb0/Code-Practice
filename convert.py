import re

def convert_to_markdown(input_text: str) -> str:
  def extract(section: str) -> str:
    pattern = rf"### {section}\s+(.*?)(?=\n### |\Z)"
    m = re.search(pattern, input_text, re.DOTALL)
    if not m:
      return ""
    text = m.group(1)

    # =================================================
    # 1️⃣ table 안에 있는 img만 추출 → figure로 변환
    # =================================================
    def table_img_repl(match):
      src = match.group(1)
      return (
        "\n\n"
        "<figure style=\"text-align:center;\">\n"
        f"  <img src=\"{src}\" style=\"max-width: 420px; width: 100%;\" />\n"
        "</figure>\n\n"
      )

    text = re.sub(
      r'<table.*?>.*?<img[^>]*src="([^"]+)"[^>]*>.*?</table>',
      table_img_repl,
      text,
      flags=re.DOTALL
    )

    # =================================================
    # 2️⃣ 남은 table 전체 제거
    # =================================================
    text = re.sub(r"<table.*?>.*?</table>", "", text, flags=re.DOTALL)

    # =================================================
    # 3️⃣ 일반 img → figure 변환
    # =================================================
    def img_repl(match):
      src = match.group(1)
      return (
        "\n\n"
        "<figure style=\"text-align:center;\">\n"
        f"  <img src=\"{src}\" style=\"max-width: 420px; width: 100%;\" />\n"
        "</figure>\n\n"
      )

    text = re.sub(
      r'<img[^>]*src="([^"]+)"[^>]*>',
      img_repl,
      text
    )

    # =================================================
    # 4️⃣ <p ...> 제거
    # =================================================
    text = re.sub(r"<p[^>]*>", "", text)
    text = text.replace("</p>", "")

    # =================================================
    # 5️⃣ 나머지 HTML 태그 제거
    # =================================================
    text = re.sub(r"</?[^>]+>", "", text)

    # =================================================
    # 6️⃣ BOJ 설명에 섞인 헤더 제거
    # =================================================
    text = re.sub(r"^#+ .*?$", "", text, flags=re.MULTILINE)

    # =================================================
    # 7️⃣ 줄바꿈 정리
    # =================================================
    text = re.sub(r"\n{3,}", "\n\n", text)

    return text.strip()

  # 문제 링크 추출
  link = ""
  m = re.search(r"\[문제 링크\]\((.*?)\)", input_text)
  if m:
    link = m.group(1)

  category = extract("분류")
  desc = extract("문제 설명")
  inp = extract("입력")
  out = extract("출력")

  return f"""
[문제 링크]({link})

---

## 🔷 분류
{category}

## ✒️ 문제 설명
{desc}

## ⬅️ 입력
{inp}

## ➡️ 출력
{out}
""".strip() + "\n"
