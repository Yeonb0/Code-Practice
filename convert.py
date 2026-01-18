import re

def convert_to_markdown(input_text):
  def clean(text):
    return text.replace("<p>", "").replace("</p>", "").strip()

  link = ""
  m = re.search(r"\[문제 링크\]\((.*?)\)", input_text)
  if m:
    link = m.group(1)

  category = ""
  m = re.search(r"### 분류\s+(.*)", input_text)
  if m:
    category = m.group(1).split("\n")[0].strip()

  desc = ""
  m = re.search(r"### 문제 설명\s+(.*?)\n###", input_text, re.DOTALL)
  if m:
    desc = clean(m.group(1))

  inp = ""
  m = re.search(r"### 입력\s+(.*?)\n###", input_text, re.DOTALL)
  if m:
    inp = clean(m.group(1))

  out = ""
  m = re.search(r"### 출력\s+(.*)", input_text, re.DOTALL)
  if m:
    out = clean(m.group(1))

  return f"""
[문제 링크]({link})

---

### 분류
- {category}

### 문제 설명
{desc}

### 입력
{inp}

### 출력
{out}
"""
