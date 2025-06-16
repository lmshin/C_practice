#include<stdio.h>

//매크로 정의
#define OS_WINDOWS
//#define OS_LINUX
//#define DEBUG_MODE
#define VERSION 2

int main() {
	printf("--- 전처리기 예제 시작 ---\n");

	//1.운영체제에 따른 조건부 컴파일
	#if defined(OS_WINDOWS)
		printf("이 코드는 Windows 환경에서 컴파일 되었습니다.\n");
	#elif defined(OS_LINUX)
		printf("이 코드는 Linux 환경에서 컴파일 되었습니다.\n");
	#else
		printf("이 코드는 알수 없는 OS 환경에서 컴파일 되었습니다.\M");
	#endif

	printf("\n");

	//2. 디버그/릴리즈 모드에 따른 조건부 컴파일
	#if defined(DEBUG_MODE)
		printf("디버그 모드입니다. 상세 로그가 출력됩니다.\
	n");
	#else
	printf("릴리즈 모드입니다. 최적화된 코드가 실행됩니다.")
	#endif

		// 3. 복합 조건 (&&, || 사용 가능)
		// #define HAS_FEATURE_A
		// #define HAS_FEATURE_B
	#if defined(HAS_FEATURE_A) && defined(HAS_FEATURE_B)
		printf("기능 A와 기능 B 모두 활성화되어 있습니다.\n");
	#elif defined(HAS_FEATURE_A) || defined(HAS_FEATURE_B)
		printf("기능 A 또는 기능 B 중 하나 이상 활성화되어 있습니다.\n");
	#else
		printf("어떤 기능도 활성화 되어있지 않습니다.\n");
	#endif

	printf("\n--- 전처리기 예제 종료 ---\n");

	return 0;
}
}