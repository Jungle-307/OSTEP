# 운영체제 스터디
**⌜운영체제: 아주 쉬운 세 가지 이야기⌟**<wbr>를 14주 동안 함께 읽고, 발표하고, 과제를 푸는 스터디입니다.<br><br>
<img src=https://github.com/user-attachments/assets/f307b220-a4f5-480c-a55d-ceee6076fd79 width=150>
<em>(원서: [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/))</em>

<br>

## ✏️ 스터디 진행 방식
* 일시: 14주간(9월 1일~12월 9일) 매주 월/화 9시
* 장소: 디스코드 std-os 음성 채팅방
* 매주 흐름:
    - 1주 동안&nbsp; [커리큘럼 레퍼런스](https://os2024.jeju.ai/index.html)를 따라 학습 (<em>Lab은 선택사항이지만 학습 권장</em>)
    - 스터디 당일 발표자 3명 랜덤 뽑기
    - 모두가 공부한 내용 공유 (<em>블로그/깃헙 등 자유 양식</em>)
    - 발표: 3명x10분 내외 (<em>새롭게 알게 된 점, 어려웠던/궁금했던 점, 추가로 조사한 부분 등 자신이 소화한 내용 위주로</em>)
    - 문제풀이: 30분
<br>

## ✨ 주차별 학습 내용
### I. 개요
---
<details > <summary><strong>1주차: 아주 쉬운 세 가지 이야기</strong></summary>
&nbsp; - 운영체제 개요
</details>

### II. 가상화
---
<details > <summary><strong>2주차: 가상화의 세계</strong></summary>
&nbsp; - 프로세스의 개념 / 프로세스 API<br>
&nbsp; - 제한적 직접 실행 원리<br>
&nbsp; - 리눅스 셸<br>
&nbsp; - 🧪 <em>(선택) Lab:</em> Shell<br>
&nbsp; - 📝 <em>Homework:</em> 프로세스<br>
</details> 

<details > <summary><strong>3주차: CPU 가상화 1</strong></summary>
&nbsp; - 스케줄링 개요<br>
&nbsp; - 🧪 <em>(선택) Lab:</em> 프로세스 생성과 실행 기초<br>
&nbsp; - 📝 <em>Homework:</em> 스케줄링<br>
</details>

<details > <summary><strong>4주차: CPU 가상화 2</strong></summary>
&nbsp; - 스케줄링: 멀티 레벨 피드백 큐<br>
&nbsp; - 스케줄링: 비례 배분<br>
&nbsp; - 🧪 <em>(선택) Lab:</em> 스케줄링 알고리즘 시뮬레이터<br>
&nbsp; - 🧪 <em>(선택) Lab:</em> Lottery 스케줄링 알고리즘 구현<br>
&nbsp; - 📝 <em>Homework:</em> 비례 배분<br>
</details> 

<details > <summary><strong>5주차: 메모리 가상화 1</strong></summary>
&nbsp; - 주소 공간의 개념<br>
&nbsp; - 메모리 관리 API<br>
&nbsp; - 🧪 <em>(선택) Lab:</em> 메모리 구조 탐색하기<br>
</details> 

<details > <summary><strong>6주차: 메모리 가상화 2</strong></summary>
&nbsp; - 주소 변환의 원리<br>
&nbsp; - 세그멘테이션<br>
&nbsp; - 🧪 <em>(선택) Lab:</em> 주소 변환 시뮬레이션<br>
&nbsp; - 📝 <em>Homework:</em> 주소 변환의 원리<br>
</details> 

<details > <summary><strong>7주차: 메모리 가상화 3</strong></summary>
&nbsp; - 빈 공간 관리<br>
&nbsp; - 📝 <em>Homework:</em> 빈 공간 관리<br>
</details> 

<details > <summary><strong>8주차: 메모리 가상화 4</strong></summary>
&nbsp; - 페이징: 개요<br>
&nbsp; - 페이징: 더 빠른 변환(TLB)<br>
&nbsp; - 물리 메모리 크기의 극복: 메커니즘<br>
</details>

### III. 병행성
---
<details > <summary><strong>9주차: 병행성 1</strong></summary>
&nbsp; - 병행성: 개요<br>
&nbsp; - 쓰레드 API<br>
</details> 

<details > <summary><strong>10주차: 병행성 2</strong></summary>
&nbsp; - 락<br>
&nbsp; - 락 기반의 병행 자료 구조<br>
</details> 

<details > <summary><strong>11주차: 병행성 3</strong></summary>
&nbsp; - 컨디션 변수<br>
&nbsp; - 세마포어<br>
</details>

### IV. 영속성
---
<details > <summary><strong>12주차: 영속성 1</strong></summary>
&nbsp; - I/O 장치<br>
&nbsp; - 파일과 디렉터리<br>
</details> 

<details > <summary><strong>13주차: 영속성 2</strong></summary>
&nbsp; - 데이터 무결성과 보호<br>
&nbsp; - 파일 시스템 구현<br>
</details>

### V. 분산
---
<details > <summary><strong>14주차: 분산</strong></summary>
&nbsp; - 분산 시스템<br>
</details>

<br>

## 🗂 파일 컨벤션
* x주차 하위에 자신의 이름 폴더 생성
* 이론 파일: `x주차.md`
* (+ 과제, 실습 파일: 자유 형식)

e.g.
```
1주차/
└─ 안 ○ ○/
   ├─ 1주차.md                  # 주차별 학습한 이론 파일
   ├─ include/
   │  └─ common.h               # 공통 선언/매크로/타입
   └─ src/
      ├─ cpu.c                  # CPU 관련 실습/데모
      ├─ io.c                   # I/O 관련 실습/데모
      ├─ mem.c                  # 메모리 관련 실습/데모
      ├─ threads.c              # 스레드 관련 실습/데모
      └─ main.c                 # 실행 엔트리
```
<br>

## 💬 커밋 컨벤션
* 포맷<br>
**`타입(파일명): 작업 내용 설명`**

    * 타입
        - `feat`: 새로운 파일 추가
        - `fix`: 버그 수정
        - `docs`: 문서 생성, 수정
        - `refactor`: 코드 리팩토링
        - `chore`: 설정 관련
    * 파일명
        - 파일이 다수일 경우는 '*'로 표기

e.g.
```
docs(README.md): 스터디 내용 및 규칙 추가
feat(*): 2주차 이론 및 과제 
```
<br>

## 📖 레퍼런스
* 커리큘럼: https://os2024.jeju.ai/index.html
* 과제: https://github.com/remzi-arpacidusseau/ostep-homework/
* 실습: https://github.com/entelecheia/os-2024/tree/main
