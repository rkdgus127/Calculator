
# Calculator — Collatz

**A computational benchmark based on the Collatz Conjecture.**

Collatz는 콜라츠 추측(Collatz Conjecture)을 기반으로 컴퓨터의 연산 성능과 처리 능력을 테스트하는 C++ 프로젝트입니다.

단순한 수학적 규칙을 대량으로 반복 실행하여 연산량에 따른 처리 성능을 측정하고, 프로그램이 감당할 수 있는 연산 규모를 확인할 수 있습니다.

<p align="center">

[![C++](https://img.shields.io/badge/C%2B%2B-20-00599C.svg?logo=cplusplus)](https://isocpp.org/)
[![Algorithm](https://img.shields.io/badge/Algorithm-Collatz-blueviolet.svg)](https://en.wikipedia.org/wiki/Collatz_conjecture)
[![License](https://img.shields.io/badge/License-GPL--3.0-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.html)
[![Status](https://img.shields.io/badge/Status-Active-brightgreen.svg)](https://github.com/rkdgus127/Calculator)

</p>
---

## Overview

프로그램의 규모가 커지고 연산량이 증가할수록 실행 시간과 시스템 자원 사용량도 증가합니다.

Collatz는 이러한 연산 부담을 측정하기 위해 제작되었습니다.

### Features

- **Performance Benchmark** — 대량의 반복 연산을 통한 성능 테스트
- **Progress Logging** — 연산 진행 상황을 실시간으로 출력
- **Overflow Detection** — 정수 오버플로 발생 여부 확인
- **Maximum Steps** — 각 입력값의 최대 반복 횟수 측정

## Collatz Conjecture

콜라츠 추측은 임의의 양의 정수 n에 다음 규칙을 반복 적용하는 수학적 문제입니다.

| Condition | Operation |
|:---:|:---|
| Even | n / 2 |
| Odd | 3n + 1 |

수식으로 표현하면 다음과 같습니다.

$$
C(n)=
\begin{cases}
n/2 & \text{if } n \equiv 0 \pmod 2 \\
3n+1 & \text{if } n \equiv 1 \pmod 2
\end{cases}
$$

이 과정을 반복하면 모든 양의 정수가 결국 1에 도달할 것이라는 추측입니다.

그러나 아직 모든 양의 정수에 대해 성립한다는 일반적인 수학적 증명은 발견되지 않았습니다.

## Benchmark

Collatz는 일정한 연산 단위마다 진행 상황을 로그로 출력합니다.

```text
[COLLATZ] Checked: 100000 | Verified: 100000 | Overflow: 0 | Max Steps: 350
[COLLATZ] Checked: 300000 | Verified: 100000 | Overflow: 0 | Max Steps: 442
[COLLATZ] Checked: 400000 | Verified: 100000 | Overflow: 0 | Max Steps: 440
```

### Log Format

| Field | Description |
|:---|:---|
| `Checked` | 누적 검사 수 |
| `Verified` | 해당 구간에서 검증된 수 |
| `Overflow` | 정수 오버플로 발생 횟수 |
| `Max Steps` | 검사 과정에서 기록된 최대 반복 횟수 |

## Technology

| Category | Specification |
|:---|:---|
| Language | C++ |
| Algorithm | Collatz Conjecture |
| License | GNU GPL v3.0 |

## License

This project is licensed under the **GNU General Public License v3.0**.

You may use, modify, and redistribute this software under the terms of GPL-3.0.

See [LICENSE](LICENSE) for more information.

---

<p align="center">
  <sub>Calculate. Measure. Challenge.</sub>
</p>
