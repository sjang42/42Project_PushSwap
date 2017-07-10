# Push_Swap - sjang@student.42.us.org

A C program that sort data using two stack with limited operation.

## 목차
* [PushSwap이란 무엇인가?](#PushSwap이란-무엇인가?)
* [개발 환경](#개발-환경)
* [사용 함수 제한](#사용-함수-제한)
* [빌드 방법](#빌드-방법)

## PushSwap이란 무엇인가?

* 개요
	* [Push_Swap][1]은 [42 Silicon Valley][2]의 개인 프로젝트입니다.
	* 제한된 환경에서 주어진 수를 정렬하는 알고리즘을 고안하는 문제입니다.

* 이 소스코드는 프로젝트의 결과물인 `push_swap` 프로그램과 `checker`프로그램을 동시에 생성합니다.

*참고*: *데이터를 정렬하기 위하여 배열, 연결리스트 등의 자료구조를 이용하는 다양한 [알고리즘][4]이 있습니다. 이번 프로젝트의 목표는 두 개의 스택(A, B)이라는 제한된 자료구조 내에서 제한된 명령을 가지고 수를 정렬하는 것입니다.*

### 결과물1 - push_swap

* `push_swap`프로그램은 숫자 데이터를 입력받아 데이터를 정렬하는 데 필요한 아래 규칙의 명령들을 출력합니다.
* 숫자 데이터를 띄어쓰기로 구분하여 입력받으며 아래 명령과 같이 사용합니다.

	./push_swap 2 3 1 4


	rra


	rra

	sa


	ra

### 결과물2 - checker

* `checker`는 숫자 데이터를 입력 받은 후 프로그램 실행 중 아래 규칙의 명령을 입력 받습니다.
* 명령이 종료된 후 checker는 데이터가 정렬되어 있는지 확인하여 OK 또는 KO를 출력합니다. 
* 아래 명령과 같이 사용합니다.

	./checker 2 3 1 4


	rra


	rra


	sa


	ra


	OK

### 규칙

두 개의 스택 A, B와 아래 제시된 11개의 명령을 이용하여 수를 정렬해야합니다.

* **sa**  :	swap A - 스택 A의 첫 두 수의 위치를 교환합니다. (A에 하나 이하의 수가 있는 경우에는 아무 일도 하지 않습니다.)
* **sb**  :	swap B - 스택 B의 첫 두 수의 위치를 교환합니다. (B에 하나 이하의 수가 있는 경우에는 아무 일도 하지 않습니다.)
* **ss**  :	sa와 sb를 동시에 진행하며 하나의 명령으로 간주합니다. 
* **pa**  :	push A - 스택 B의 첫 번째 수를 A의 첫 번째로 이동합니다. (B에 하나 이하의 수가 있는 경우에는 아무 일도 하지 않습니다.)
* **pb**  :	push B - 스택 A의 첫 번째 수를 B의 첫 번째로 이동합니다. (B에 하나 이하의 수가 있는 경우에는 아무 일도 하지 않습니다.)
* **ra**  :	rotate A - A의 모든 수를 한 칸 앞으로 이동합니다. A의 첫번째 수는 이동 후 마지막 수가 됩니다.
* **rb**  :	rotate B - B의 모든 수를 한 칸 앞으로 이동합니다. B의 첫번째 수는 이동 후 마지막 수가 됩니다.
* **rr**  :	ra와 rb를 동시에 진행하며 하나의 명령으로 간주합니다.
* **rra** :	reverse rotate A - A의 모든 수를 한 칸 뒤로 이동합니다. A의 마지막 수는 이동 후 첫번째 수가 됩니다.
* **rrb** :	reverse rotate B - B의 모든 수를 한 칸 뒤로 이동합니다. B의 마지막 수는 이동 후 첫번째 수가 됩니다.
* **rrr** :	rra와 rrb를 동시에 진행합니다.

### 예시
 
    a : 7, 1, -8, 6, 5
    b :

**ra**

    a : 1, -8, 6, 5, 7
    b :

**pb**

    a : -8, 6, 5, 7
    b : 1

**pb**

    a : 6, 5, 7
    b : -8, 1

**ss**

    a : 5, 6, 7
    b : 1, -8

**pa**

    a : 1, 5, 6, 7
    b : -8

**pa**

    a : -8, 1, 5, 6, 7
    b :

## 개발 환경

* OS
	* Ubuntu 16.04
* Language
	* C
* Compiler
	* gcc
* builder
	* MAKE
* 사용 라이브러리
	* [42Project_Libft][4]

## 사용 함수 제한

**NOTE:** 42프로젝트는 c 함수 사용을 아래 함수로 제한하고 있습니다.

* 입출력 관련 함수
	* open
	* close
	* read
	* write

* 메모리 관련 함수
	* malloc
	* free

* 에러 관련 함수
	* exit

* 이외 필요한 함수(strlen 등)를 프로젝트[libft][3]에서 위 함수의 제한 내에서 직접 만들어 사용하고 있습니다.

## 빌드 방법

**NOTE:** MAKE가 설치되어 있어야 합니다.

	sudo apt-get install make

깃을 클론합니다.

	git clone https://github.com/sjang42/42Project_PushSwap.git
	cd 42Project_PushSwap

해당 디렉터리에서 서브깃을 업데이트한 뒤 Makefile을 이용하여 빌드합니다.

	git submodule init
	git submodule update
	make

`push_swap` 프로그램과 `checker`프로그램이 프로젝트 루트 디렉터리에 생성되었습니다.

## 사용 방법

**push_swap**

아래 명령은 데이터 [7, 1, -8, 6, 5]를 정렬하기 위해 필요한 명령들 을 출력합니다.
데이터가 중복되거나 4바이트 이상일 경우 Error를 출력합니다.

	./push_swap 7, 1, -8, 6, 5

**checker**

아래 명령은 데이터 [7, 1, -8, 6, 5]를 정렬하기 위해 필요한 명령을 출력하고, 그 결과를 check로 확인합니다. *-s* 옵션은 진행 과정을 출력합니다.
check는 명령의 결과로 수가 정렬된 경우 OK를 출력하고 수가 정렬되지 않은 경우 KO를 출력합니다.

	./push_swap 7, 1, -8, 6, 5 | ./checker -s 7, 1, -8, 6, 5

[1]: https://github.com/sjang42/42Project_PushSwap/blob/master/push_swap.en.pdf
[2]: http://42.us.org "42 USA"
[3]: https://github.com/sjang42/42Project_Libft
[4]: https://en.wikipedia.org/wiki/Sorting_algorithm
