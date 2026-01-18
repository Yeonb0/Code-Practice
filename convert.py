import re

def convert_to_markdown(input_text: str) -> str:
  def extract(section: str) -> str:
    """
    ### 섹션명
    내용
    ### 다음섹션
    구조에서 '내용'만 안전하게 추출
    """
    pattern = rf"### {section}\s+(.*?)(?=\n### |\Z)"
    m = re.search(pattern, input_text, re.DOTALL)
    if not m:
      return ""
    text = m.group(1)

    # HTML 태그 제거
    text = text.replace("<p>", "").replace("</p>", "")

    # 불필요한 마크다운 헤더 제거
    text = re.sub(r"^#+ .*?$", "", text, flags=re.MULTILINE)

    # 과도한 줄바꿈 정리
    text = re.sub(r"\n{3,}", "\n\n", text)

    return text.strip()

  # 문제 링크
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
