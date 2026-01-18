import re

def convert_to_markdown(input_text):
  link = ""
  m = re.search("\\[문제 링크\\]\\((.*?)\\)", input_text)
  if m:
    link = m.group(1)

  cat = ""
  m = re.search("### 분류\\s+(.*)", input_text)
  if m:
    cat = m.group(1).split("\\n")[0]

  desc = ""
  m = re.search("### 문제 설명\\s+(.*?)\\n###", input_text, re.DOTALL)
  if m:
    desc = m.group(1).strip()

  inp = ""
  m = re.search("### 입력\\s+(.*?)\\n###", input_text, re.DOTALL)
  if m:
    inp = m.group(1).strip()

  out = ""
  m = re.search("### 출력\\s+(.*)", input_text, re.DOTALL)
  if m:
    out = m.group(1).strip()

  text = ""
  text += f"[문제 링크]({link})\\n\\n"
  text += "---\\n\\n"
  text += "### 분류\\n"
  text += f"- {cat}\\n\\n"
  text += "### 문제 설명\\n"
  text += desc + "\\n\\n"
  text += "### 입력\\n"
  text += inp + "\\n\\n"
  text += "### 출력\\n"
  text += out + "\\n"

  return text
