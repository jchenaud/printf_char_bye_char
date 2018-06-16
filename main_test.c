# include "includes/ft_printf.h"
//# include "Core_function.c"
# include <stdio.h>
void f(void)
{
  return ;
}

int main(int c , char **v)
{
  int i;
  i = 42;
  char *str;
  void *p = f;

  str = "efwefwfewfewfewfewefweffofkewfokfokwefokpwepofwefekwofkwoefpkowfwefw";
  printf("%d",printf("origi : %p\n", &i));
  printf("%d",ft_printf("minee : %p\n", &i));
printf("\n");
printf("\n");
printf("\n");

  printf("%d",printf("origi : %p\n", &str));
  printf("%d",ft_printf("minee : %p\n", &str));

  printf("\n");
printf("\n");
printf("\n");

  printf("%d",printf("origi : %p\n", &p));
  printf("%d",ft_printf("minee : %p\n", &p));

  printf("\n");
printf("\n");
printf("\n");

  printf("%d",printf("origi : %p\n", &ft_printf));
  printf("%d",ft_printf("minee : %p\n", &ft_printf));
  printf("\n");
printf("\n");
printf("\n");

  printf("%d",printf("origi : %p\n", 0));
  printf("%d",ft_printf("minee : %p\n", 0));

  printf("\n");
printf("\n");

  printf("%d",printf("origi : %i\n", 42));
  printf("%d",ft_printf("minee : %i\n", 42));



  printf("\n");
printf("\n");

  printf("%d",printf("before %x after", 42));
  printf("%d",ft_printf("before %x after", 42));

   printf("\n");
printf("\n");
printf("%d",printf("before %05d after", 24));
  printf("\n");
  printf("%d",ft_printf("before %05d after", 24));
  printf("\n");  printf("\n");
  printf("%d",printf("before % 05D after", 24));
  printf("\n");
  printf("%d",ft_printf("before % 05D after", 24));
  printf("\n");
printf("%f",0);
}
	
// //printf("//////////////////////////////////////////////////////////\n");
// 	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
// 	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
// 	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
// 	//if (c == 2)
// 	//	while(1)
// 	//getchar();
// 	 ft_printf("%s\n","abs");
// 	// getchar();
// 	 ft_printf("@moulitest: %s", NULL);
// 	// getchar();
// 	 ft_printf("%10s is a string", "this");
// 	// getchar();
// 	 ft_printf("%.2s is a string", "this");
// 	// getchar();



// 	ft_printf("salut\n");
// 	ft_printf("%#8x", 42);
// 	//printf("\n");
// 	//printf("%#8x", 42);
// 	//printf("\n");
// 	//printf("\n");

	
	
//   	//printf("/////////////////////////////////////////////////////////////////\n");
	
// 	 //printf("%#-08x\n", 42);
//   	ft_printf("%#-08x", 42);
//   	//printf("/////////////////////////////////////////////////////////////////\n");
//   	 //printf("%#-010x\n", 42);
//   	ft_printf("%#-010x", 42);
//   	//printf("\n");
//   	//printf("/////////////////////////////////////////////////////////////////\n");
//   	//printf("/////////////////////////////////////////////////////////////////\n");

//   	 ////printf("%#.x\n", 5);
//   	 //ft_printf("%#.x\n", 5);
//   	//printf("/////////////////////////////////////////////////////////////////\n");
//   	//printf("/////////////////////////////////////////////////////////////////\n");

//   	   ft_printf("%.0%\n");
//   	   //printf("%.0%\n");


//   	//printf("/////////////////////////////////////////////////////////////////\n");
//   	//printf("/////////////////////////////////////////////////////////////////\n");




// 	//printf("salut\n");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	ft_printf("salut %s bye\n","cocorico");
// //	//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("salut %s bye\n","cocorico");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	ft_printf("salut %c%s%d\n",'c',"oco",-54);
// 	//printf("salut %c%s%d\n",'c',"oco",-54);
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("salut %%%s\n","salut");
// 	ft_printf("salut %%%s\n","salut");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("salut %    %%s\n","salut");
// 	ft_printf("salut %    %%s\n","salut");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("[%p]\n","salut");
// 	ft_printf("[%p]\n","salut");
// 		//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("//////////////////////////////////////////////////////////\n");
// ft_printf("\n");
// //printf("\n");
// //printf("//////////////////////////////////////////////////////////\n");
// 		//printf("%5%");
// 		//printf("//////////////////////////////////////////////////////////\n");
// 		ft_printf("%5%");
// 		//printf("//////////////////////////////////////////////////////////\n");

// 		//ft_printf("[ %5% ]\n");
// 		////printf("[ %5% ]\n");
// 		//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	ft_printf("%-5%");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("%-5%");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	ft_printf("%.0%");
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	ft_printf("%x", 42);
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	ft_printf("%10x", 42);
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	ft_printf("%lx", 4294967296);
// 	//printf("//////////////////////////////////////////////////////////\n");

// 	 ft_printf("%010x", 542);
// 	//printf("//////////////////////////////////////////////////////////\n");
	
// 	ft_printf("%5%");
// 	//printf("//////////////////////////////////////////////////////////\n");
// ///ft_printf("%#llx", 9223372036854775807); segfaul!!!!!!
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	ft_printf("%#x", 0);
// 	//printf("//////////////////////////////////////////////////////////\n");
// 	getchar();
// 	printf("@moulitest: %#.x %#.0x\n", 0, 0);
// 	printf("@moulitest: %#.x %#.0x\n", 0, 0);
// 	printf("@moulitest: %#.x %#.0x\n", 0, 0);
// 	//if (c == 2)
	
// //all chekr test;

// //001 
//   ft_printf("");
//   getchar();

//   //    0) -->k<--
//   //    0) --><--

// //002 
//   ft_printf("\n");
//   getchar();

//   //    1) -->$\nk<--
//   //    1) -->$\n<--

// // //003 
//   ft_printf("test");
// //   getchar();

// //   //    4) -->testk<--
// //   //    4) -->test<--

// // //004 
//   ft_printf("test\n");
// //   getchar();

// //   //    5) -->test$\nk<--
// //   //    5) -->test$\n<--

// // //005 
//   ft_printf("1234");
// //   getchar();

// //   //    4) -->1234k<--
// //   //    4) -->1234<--

// // //006 
//   ft_printf("%%");
// //   getchar();

// //   //    1) -->%k<--
// //   //    1) -->%<--

// // //007 
//   ft_printf("%5%");
// //   getchar();

// //   //    5) -->    %k<--
// //   //    5) -->    %<--

// // //008 
//   ft_printf("%-5%");
// //   getchar();

// //   //    5) -->%    k<--
// //   //    5) -->%    <--

// // //009 
//   ft_printf("%.0%");
// //   getchar();

//   //    1) -->%k<--
//   //    1) -->%<--

// //010 (char *)
//   ft_printf("%%", "test");
//  // getchar();

//   //    1) -->%k<--
//   //    1) -->%<--

// //011 (char *)
//   ft_printf("%   %", "test");
//   // getchar();
//   //    1) -->%k<--
//   //    1) -->%<--

// //012 (int)
//   getchar();
//   ft_printf("%x wdwdwd %x", 42,42);
//   getchar();
//   //    2) -->2ak<--
//   //    2) -->2a<--

// //013 (int)
//   ft_printf("%X", 42);
//   //    2) -->2Ak<--
//   //    2) -->2A<--

// //014 (int)
//   ft_printf("%x", 0);
//   //    1) -->0k<--
//   //    1) -->0<--

// //015 (int)
//   ft_printf("%X", 0);
//   //    1) -->0k<--
//   //    1) -->0<--

// //016 (int)
//   ft_printf("%x", -42);
//   //    8) -->ffffffd6k<--
//   //    8) -->ffffffd6<--

// //017 (int)
//   ft_printf("%X", -42);
//   //    8) -->FFFFFFD6k<--
//   //    8) -->FFFFFFD6<--

// //018 (int)
//   ft_printf("%x", 4294967296);
//   //    1) -->0k<--
//   //    1) -->0<--

// //019 (int)
//   ft_printf("%X", 4294967296);
//   //    1) -->0k<--
//   //    1) -->0<--

// //020 (int)
// //  ft_printf("%x", test);
//   //    1) -->0k<--
//   //    1) -->0<--

// //021 (int)
//   ft_printf("%10x", 42);
//   //   10) -->        2ak<--
//   //   10) -->        2a<--

// //022 (int)
//   ft_printf("%-10x", 42);
//   //   10) -->2a        k<--
//   //   10) -->2a        <--

// //023 (int)
//   ft_printf("%lx", 4294967296);
//   //    9) -->100000000k<--
//   //    9) -->100000000<--

// //024 (int)
//   ft_printf("%llX", 4294967296);
//   //    9) -->100000000k<--
//   //    9) -->100000000<--

// //025 (int)
//   ft_printf("%hx", 4294967296);
//   //    1) -->0k<--
//   //    1) -->0<--

// //026 (int)
//   ft_printf("%hhX", 4294967296);
//   //    1) -->0k<--
//   //    1) -->0<--

// //027 (int)
//   ft_printf("%jx", 4294967295);
//   //    8) -->ffffffffk<--
//   //    8) -->ffffffff<--

// //028 (int)
//   ft_printf("%jx", 4294967296);
//   //    9) -->100000000k<--
//   //    9) -->100000000<--

// //029 (int)
//   ft_printf("%jx", -4294967296);
//   //   16) -->ffffffff00000000k<--
//   //   16) -->ffffffff00000000<--

// //030 (int)
//   ft_printf("%jx", -4294967297);
//   //   16) -->fffffffeffffffffk<--
//   //   16) -->fffffffeffffffff<--

// //031 (int)
// //  ft_printf("%llx", 9223372036854775807);
//   //   16) -->7fffffffffffffffk<--
//   //   16) -->7fffffffffffffff<--

// //032 (int)
//  // ft_printf("%llx", 9223372036854775808);
//   //   16) -->7fffffffffffffffk<--
//   //   16) -->7fffffffffffffff<--

// //033 (int)
//   ft_printf("%010x", 542);
//   //   10) -->000000021ek<--
//   //   10) -->000000021e<--

// //034 (int)
//   ft_printf("%-15x", 542);
//   //   15) -->21e            k<--
//   //   15) -->21e            <--

// //035 (int)
//   ft_printf("%2x", 542);
//   //    3) -->21ek<--
//   //    3) -->21e<--

// //036 (int)
//   ft_printf("%.2x", 5427);
//   //    4) -->1533k<--
//   //    4) -->1533<--

// //037 (int)
//    printf("%5.x\n", 5427);
//    printf("%5.10x\n", 5427);
//   //getchar();


//    ft_printf("%5.2x", 5427);
//   //getchar();
   
//   //    5) --> 1533k<--
//   //    5) --> 1533<--

// //038 (int)
//   ft_printf("%#x", 42);
//   //    4) -->0x2ak<--
//   //    4) -->0x2a<--

// //039 (int)
// //  ft_printf("%#llx", 9223372036854775807);
//   //   18) -->0x7fffffffffffffffk<--
//   //   18) -->0x7fffffffffffffff<--

// //040 (int)
//   ft_printf("%#x", 0);
//   //    1) -->0k<--
//   //    1) -->0<--

// //041 (int)
//   ft_printf("%#x", 42);
//   //    4) -->0x2ak<--
//   //    4) -->0x2a<--

// //042 (int)
//   ft_printf("%#X", 42);
//   //    4) -->0X2Ak<--
//   //    4) -->0X2A<--

// //043 (int)
//   ft_printf("%#8x", 42);
//   //    8) -->    0x2ak<--
//   //    8) -->    0x2a<--

// //044 (int)
//   ft_printf("%#08x", 42);
//   //    8) -->0x00002ak<--
//   //    8) -->0x00002a<--

// //045 (int)
//   ft_printf("%#-08x", 42);
//   //    8) -->0x2a    k<--
//   //    8) -->0x2a    <--

// ////046 (int)
//   ft_printf("@moulitest: %#.x %#.0x", 0);
//   //  // 13) -->@moulitest:  0x00k<--
//   //  // 13) -->@moulitest:  <--
//  // getchar();

// ////047 (int)
//   ft_printf("@moulitest: %.x %.0x", 0, 0);
//   //   13) -->@moulitest:  0k<--
//   //   13) -->@moulitest:  <--
//  // getchar();

// //048 (int)
//   ft_printf("@moulitest: %5.x %5.0x", 0, 0);
//   //   23) -->@moulitest:     0     0k<--
//   //   23) -->@moulitest:            <--
//  //getchar();

// //049 (char *)
//   ft_printf("%s", "abc");
//   //    3) -->abck<--
//   //    3) -->abc<--
//  // getchar();

// //050 (char *)
//   ft_printf("%s", "this is a string");
//   //   16) -->this is a stringk<--
//   //   16) -->this is a string<--

// //051 (char *)
//   ft_printf("%s ", "this is a string");
//   //   17) -->this is a string k<--
//   //   17) -->this is a string <--

// //052 (char *)
//   ft_printf("%s  ", "this is a string");
//   //   18) -->this is a string  k<--
//   //   18) -->this is a string  <--

// //053 (char *)
//   ft_printf("this is a %s", "string");
//   //   16) -->this is a stringk<--
//   //   16) -->this is a string<--

// //054 (char *)
//   ft_printf("%s is a string", "this");
//   //   16) -->this is a stringk<--
//   //   16) -->this is a string<--

// //055 (char *)
//   ft_printf("Line Feed %s", "\n");
//   //   11) -->Line Feed $\nk<--
//   //   11) -->Line Feed $\n<--

// //056 (char *)
//   ft_printf("%10s is a string", "this");
//   //   22) -->      this is a stringk<--
//   //   22) -->      this is a string<--

// //057 (char *)
//   ft_printf("%.2s is a string", "this");
//   //   14) -->th is a stringk<--
//   //   14) -->th is a string<--
// getchar();
// //058 (char *)
//   ft_printf("%5.2s is a string", "this");
//   //   14) -->2s is a stringk<--
//   //   17) -->   th is a string<--
//  getchar();

// //059 (char *)
//   ft_printf("%10s is a string", "");
//   //   22) -->           is a stringk<--
//   //   22) -->           is a string<--
//  getchar();

// //060 (char *)
//   ft_printf("%.2s is a string", "");
//   //   14) -->^@T is a stringk<--
//   //   12) --> is a string<--
//  getchar();

// //061 (char *)
//   ft_printf("%5.2s is a string", "");
//   //   14) -->2s is a stringk<--
//   //   17) -->      is a string<--
//  getchar();

// //062 (char *)
//   ft_printf("%-10s is a string", "this");
//   //   22) -->       is a stringk<--
//   //   22) -->this       is a string<--
//  getchar();

// //063 (char *)
//   ft_printf("%-.2s is a string", "this");
//   //   15) -->.2s is a stringk<--
//   //   14) -->th is a string<--

//  getchar();
// //064 (char *)
//   ft_printf("%-5.2s is a string", "this");
//   //   14) -->2s is a stringk<--
//   //   17) -->th    is a string<--
//  getchar();

// //065 (char *)
//   ft_printf("%-10s is a string", "");
//   //   22) -->           is a stringk<--
//   //   22) -->           is a string<--
//  getchar();

// //066 (char *)
//   ft_printf("%-.2s is a string", "");
//   //   15) -->.2s is a stringk<--
//   //   12) --> is a string<--

// //067 (char *)
//   ft_printf("%-5.2s is a string", "");
//   //   14) -->2s is a stringk<--
//   //   17) -->      is a string<--

// //068 (char *)
//   ft_printf("%s %s", "this", "is");
//   //    7) -->this isk<--
//   //    7) -->this is<--

// //069 (char *)
//   ft_printf("%s %s %s", "this", "is", "a");
//   //    9) -->this is ak<--
//   //    9) -->this is a<--

// //070 (char *)
//   ft_printf("%s %s %s %s", "this", "is", "a", "multi");
//   //   15) -->this is a multik<--
//   //   15) -->this is a multi<--

// //071 (char *)
//   ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
//   //   27) -->this is a multi string. gg!k<--
//   //   27) -->this is a multi string. gg!<--

// //072 (char *)
//   ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
//   //   18) -->thisisamultistringk<--
//   //   18) -->thisisamultistring<--

// //073 (NULL)
//   ft_printf("@moulitest: %s", NULL);
//   //   18) -->@moulitest: (null)k<--
//   //   18) -->@moulitest: (null)<--

// //074 (NULL)
//   ft_printf("%.2c", NULL);
//   //    3) -->^@  k<--
//   //    1) -->^@<--

// //075 (NULL)
//  // ft_printf("%s %s", NULL, string);
//   //   13) -->(null) stringk<--
//   //   13) -->(null) string<--

// //076 (char)
//   ft_printf("%c", 42);
//   //    1) -->*k<--
//   //    1) -->*<--

// //077 (char)
//   ft_printf("%5c", 42);
//   //    6) -->*     k<--
//   //    5) -->    *<--

// //078 (char)
//   ft_printf("%-5c", 42);
//   //    6) -->*     k<--
//   //    5) -->*    <--

// //079 (char)
//   ft_printf("@moulitest: %c", 0);
//   //   13) -->@moulitest: ^@k<--
//   //   13) -->@moulitest: ^@<--

// //080 (char)
//   ft_printf("%2c", 0);
//   //    3) -->^@  k<--
//   //    2) --> ^@<--

// //081 (char)
//   ft_printf("null %c and text", 0);
//   //   15) -->null ^@ and textk<--
//   //   15) -->null ^@ and text<--

// //082 (char)
//   ft_printf("% c", 0);
//   //    1) -->^@k<--
//   //    1) -->^@<--

// //083 (int)
//   ft_printf("%o", 40);
//   //    0) -->k<--
//   //    2) -->50<--

// //084 (int)
//   ft_printf("%5o", 41);
//   //    5) -->     k<--
//   //    5) -->   51<--

// //085 (int)
//   ft_printf("%05o", 42);
//   //    5) -->00000k<--
//   //    5) -->00052<--

// //086 (int)
//   ft_printf("%-5o", 2500);
//   //    5) -->     k<--
//   //    5) -->4704 <--

// //087 (int)
//   ft_printf("%#6o", 2500);
//   //    1) -->ok<--
//   //    6) --> 04704<--

// //088 (int)
//   ft_printf("%-#6o", 2500);
//   //    3) -->#6ok<--
//   //    6) -->04704 <--

// //089 (int)
//   ft_printf("%-05o", 2500);
//   //   10) -->          k<--
//   //    5) -->4704 <--

// //090 (int)
//   ft_printf("%-5.10o", 2500);
//   //    3) -->10ok<--
//   //   10) -->0000004704<--

// //091 (int)
//   ft_printf("%-10.5o", 2500);
//   //    2) -->5ok<--
//   //   10) -->04704     <--

// //092 (int)
//   ft_printf("@moulitest: %o", 0);
//   //   12) -->@moulitest: k<--
//   //   13) -->@moulitest: 0<--

// //093 (int)
//   ft_printf("@moulitest: %.o %.0o", 0, 0);
//   //   14) -->@moulitest:  ok<--
//   //   13) -->@moulitest:  <--

// //094 (int)
//  // char *s;
//  //  s = ft_strdup("salut");
//    ft_printf("%d %d\n", 1, -2);
//  // //  printf("%s\n",s);
//    ft_printf("%d %d %d\n", 1, 2, 33);

//    ft_printf("%d %d %d\n", 1, -2, 33);
//   // getchar();

//   printf("[@moulitest: %5.o %5.0o]\n", 0, 0);
//   ft_printf("[@moulitest: %5.o %5.0o]\n", 0, 0);
//   getchar();
//   printf("[@moulitest: %5.o]\n",0);
//   ft_printf("[@moulitest: %5.o]\n",0);
//   getchar();
//   printf("[@moulitest: %5.0o]\n",0);
//   ft_printf("[@moulitest: %5.0o]\n",0);
//   getchar();
//   printf("[@moulitest: %5.o %5.0o %-5.o %-5.0o]\n", 0, 0, 0, 0);
//   ft_printf("[@moulitest: %5.o %5.0o %-5.o %-5.0o]\n", 0, 0, 0, 0);




//   //   16) -->@moulitest: o 0ok<--
//   //   23) -->@moulitest:            <--

// //095 (int)
//   ft_printf("@moulitest: %#.o %#.0o", 0, 0);
//   //   16) -->@moulitest: o 0ok<--
//   //   15) -->@moulitest: 0 0<--

// //096 (int)
//   ft_printf("@moulitest: %.10o", 42);
//   //   22) -->@moulitest:           k<--
//   //   22) -->@moulitest: 0000000052<--

// //097 (int)
//   ft_printf("%d", 1);
//   //    0) -->1k<--
//   //    1) -->1<--

// //098 (int)
//   ft_printf("the %d", 1);
//   //    4) -->the 1k<--
//   //    5) -->the 1<--

// //099 (int)
//   ft_printf("%d is one", 1);
//   //    7) -->1 is onek<--
//   //    8) -->1 is one<--

// //100 (int)
//   ft_printf("%d", -1);
//   //    0) -->-1k<--
//   //    2) -->-1<--

// //101 (int)
//   ft_printf("%d", 4242);
//   //    0) -->4242k<--
//   //    4) -->4242<--

// //102 (int)
//   ft_printf("%d", -4242);
//   //    0) -->-4242k<--
//   //    5) -->-4242<--

// //103 (int)
//   ft_printf("%d", 2147483647);
//   //    0) -->2147483647k<--
//   //   10) -->2147483647<--

// //104 (int)
//   ft_printf("%d", 2147483648);
//   //    0) -->-2147483648k<--
//   //   11) -->-2147483648<--

// //105 (int)
//   ft_printf("%d", -2147483648);
//   //    0) -->-2147483648k<--
//   //   11) -->-2147483648<--

// //106 (int)
//   ft_printf("%d", -2147483649);
//   //    0) -->2147483647k<--
//   //   10) -->2147483647<--

// //107 (int)
//   ft_printf("% d", 42);
//   //    0) -->42k<--
//   //    3) --> 42<--

// //108 (int)
//   ft_printf("% d", -42);
//   //    0) -->-42k<--
//   //    3) -->-42<--

// //109 (int)
//   ft_printf("%+d", 42);
//   //    1) -->dk<--
//   //    3) -->+42<--

// //110 (int)
//   ft_printf("%+d", -42);
//   //    1) -->dk<--
//   //    3) -->-42<--

// //111 (int)
//   ft_printf("%+d", 0);
//   //    1) -->dk<--
//   //    2) -->+0<--

// //112 (int)
// //  ft_printf("%+d", 4242424242424242424242);
//   //    1) -->dk<--
//   //    2) -->-1<--

// //113 (int)
//   ft_printf("% +d", 42);
//   //    1) -->dk<--
//   //    3) -->+42<--

// //114 (int)
//   ft_printf("% +d", -42);
//   //    1) -->dk<--
//   //    3) -->-42<--

// //115 (int)
//   ft_printf("%+ d", 42);
//   //    2) --> dk<--
//   //    3) -->+42<--

// //116 (int)
//   ft_printf("%+ d", -42);
//   //    2) --> dk<--
//   //    3) -->-42<--

// //117 (int)
//   ft_printf("%  +d", 42);
//   //    1) -->dk<--
//   //    3) -->+42<--

// //118 (int)
//   ft_printf("%  +d", -42);
//   //    1) -->dk<--
//   //    3) -->-42<--

// //119 (int)
//   ft_printf("%+  d", 42);
//   //    3) -->  dk<--
//   //    3) -->+42<--

// //120 (int)
//   ft_printf("%+  d", -42);
//   //    3) -->  dk<--
//   //    3) -->-42<--

// //121 (int)
//   ft_printf("% ++d", 42);
//   //    2) -->+dk<--
//   //    3) -->+42<--

// //122 (int)
//   ft_printf("% ++d", -42);
//   //    2) -->+dk<--
//   //    3) -->-42<--

// //123 (int)
//   ft_printf("%++ d", 42);
//   //    3) -->+ dk<--
//   //    3) -->+42<--

// //124 (int)
//   ft_printf("%++ d", -42);
//   //    3) -->+ dk<--
//   //    3) -->-42<--

// //125 (int)
//   ft_printf("%0d", -42);
//   //    1) -->dk<--
//   //    3) -->-42<--

// //126 (int)
//   ft_printf("%00d", -42);
//   //    2) -->0dk<--
//   //    3) -->-42<--

// //127 (int)
//   ft_printf("%5d", 42);
//   //    5) -->42     k<--
//   //    5) -->   42<--

// //128 (int)
//   ft_printf("%05d", 42);
//   //    5) -->4200000k<--
//   //    5) -->00042<--

// //129 (int)
//   ft_printf("%0+5d", 42);
//      // 3) -->+5dk<--
//      // 5) -->+0042<--

// //130 (int)
//   ft_printf("%5d", -42);
//   //    5) -->-42     k<--
//   //    5) -->  -42<--

// //131 (int)
//   ft_printf("%05d", -42);
//   //    5) -->-4200000k<--
//   //    5) -->-0042<--

// //132 (int)
//   ft_printf("%0+5d", -42);
//   //    3) -->+5dk<--
//   //    5) -->-0042<--

// //133 (int)
//   ft_printf("%-5d", 42);
//   //    5) -->42     k<--
//   //    5) -->42   <--

// //134 (int)
//   ft_printf("%-05d", 42);
//   //   10) -->42          k<--
//   //    5) -->42   <--

// //135 (int)
//   ft_printf("%-5d", -42);
//   //    5) -->-42     k<--
//   //    5) -->-42  <--

// //136 (int)
//   ft_printf("%-05d", -42);
//   //   10) -->-42          k<--
//   //    5) -->-42  <--

// //137 (short)
//   ft_printf("%hd", 32767);
//   //    0) -->32767k<--
//   //    5) -->32767<--

// //138 (short)
// //  ft_printf("%hd", −32768);
//   //    0) -->0k<--
//   //    1) -->0<--

// //139 (short)
//   ft_printf("%hd", 32768);
//   //    0) -->32768k<--
//   //    6) -->-32768<--

// //140 (short)
// //  ft_printf("%hd", −32769);
//   //    0) -->0k<--
//   //    1) -->0<--

// //141 (signed char)
//   ft_printf("%hhd", 127);
//   //    0) -->127k<--
//   //    3) -->127<--

// //142 (signed char)
//   ft_printf("%hhd", 128);
//   //    0) -->128k<--
//   //    4) -->-128<--

// //143 (signed char)
//   ft_printf("%hhd", -128);
//   //    0) -->-128k<--
//   //    4) -->-128<--

// //144 (signed char)
//   ft_printf("%hhd", -129);
//   //    0) -->-129k<--
//   //    3) -->127<--

// //145 (long)
//   ft_printf("%ld", 2147483647);
//   //   10) -->2147483647k<--
//   //   10) -->2147483647<--

// //146 (long)
//   ft_printf("%ld", -2147483648);
//   //   11) -->-2147483648k<--
//   //   11) -->-2147483648<--

// //147 (long)
//   ft_printf("%ld", 2147483648);
//   //   10) -->2147483648k<--
//   //   10) -->2147483648<--

// //148 (long)
//   ft_printf("%ld", -2147483649);
//   //   11) -->-2147483649k<--
//   //   11) -->-2147483649<--

// //149 (long long)
//   //ft_printf("%lld", 9223372036854775807);
//   //    0) -->-1k<--
//   //   19) -->9223372036854775807<--

// //150 (long long)
// //  ft_printf("%lld", -9223372036854775808);
//   //    0) -->0k<--
//   //   20) -->-9223372036854775808<--

// //151 (intmax_t)
//   ft_printf("%jd", 9223372036854775807);
//   //    0) -->k<--
//   //   19) -->9223372036854775807<--

// //152 (intmax_t)
//  // ft_printf("%jd", -9223372036854775808);
//   //    0) -->k<--
//   //   20) -->-9223372036854775808<--

// //153 (ssize_t)
//   ft_printf("%zd", 4294967295);
//   //    1) -->dk<--
//   //   10) -->4294967295<--

// //154 (ssize_t)
//   ft_printf("%zd", 4294967296);
//   //    1) -->dk<--
//   //   10) -->4294967296<--

// //155 (ssize_t)
//   ft_printf("%zd", -0);
//   //    1) -->dk<--
//   //    1) -->0<--

// //156 (ssize_t)
//   ft_printf("%zd", -1);
//   //    1) -->dk<--
//   //    2) -->-1<--

// //157 (int)
//   ft_printf("%d", 1);
//   //    0) -->1k<--
//   //    1) -->1<--

// //158 (int)
//   ft_printf("%d %d", 1, -2);
//   //    1) -->1 -2k<--
//   //    4) -->1 -2<--

// //159 (int)
//   ft_printf("%d %d %d", 1, -2, 33);
//   //    2) -->1 -2 33k<--
//   //    7) -->1 -2 33<--

// //160 (int)
//   ft_printf("%d %d %d %d", 1, -2, 33, 42);
//   //    3) -->1 -2 33 42k<--
//   //   10) -->1 -2 33 42<--

// //161 (int)
//   ft_printf("%d %d %d %d gg!", 1, -2, 33, 42, 0);
//   //    7) -->1 -2 33 42 gg!k<--
//   //   14) -->1 -2 33 42 gg!<--

// //162 (int)
//   ft_printf("%4.15d", 42);
//   //    3) -->15dk<--
//   //   15) -->000000000000042<--

// //163 (int)
//   ft_printf("%.2d", 4242);
//   //    2) -->4242  k<--
//   //    4) -->4242<--

// //164 (int)
//   ft_printf("%.10d", 4242);
//   //   10) -->4242          k<--
//   //   10) -->0000004242<--

// //165 (int)
//   ft_printf("%10.5d", 4242);
//   //    2) -->5dk<--
//   //   10) -->     04242<--

// //166 (int)
//   ft_printf("%-10.5d", 4242);
//   //    2) -->5dk<--
//   //   10) -->04242     <--

// //167 (int)
//   ft_printf("% 10.5d", 4242);
//   //    2) -->5dk<--
//   //   10) -->     04242<--

// //168 (int)
//   ft_printf("%+10.5d", 4242);
//   //    5) -->10.5dk<--
//   //   10) -->    +04242<--

// //169 (int)
//   ft_printf("%-+10.5d", 4242);
//   //    6) -->+10.5dk<--
//   //   10) -->+04242    <--

// //170 (int)
//   ft_printf("%03.2d", 0);
//   //    2) -->2dk<--
//   //    3) --> 00<--

// //171 (int)
//   ft_printf("%03.2d", 1);
//   //    2) -->2dk<--
//   //    3) --> 01<--

// // //172 (int)
//   ft_printf("%03.2d\n", -1);
//   printf("%03.2d\n", -1);
//   getchar();
//   ft_printf("%3.2d\n", -1);
//   printf("%3.2d\n", -1);
//   getchar();


//   //    2) -->2dk<--
//   //    3) -->-01<--

// //173 (int)
//   ft_printf("@moulitest: %.10d", -42);
//   //   22) -->@moulitest: -42          k<--
//   //   23) -->@moulitest: -0000000042<--

// //174 (int)
//   ft_printf("@moulitest: %.d %.0d", 42, 43);
//   //   14) -->@moulitest:  dk<--
//   //   17) -->@moulitest: 42 43<--

// //175 (int)
//   ft_printf("@moulitest: %.d %.0d", 0, 0);
//   //   14) -->@moulitest:  dk<--
//   //   13) -->@moulitest:  <--

// //176 (int)
//   ft_printf("@moulitest: %5.d %5.0d", 0, 0);
//   //   16) -->@moulitest: d 0dk<--
//   //   23) -->@moulitest:            <--

// //177 (unsigned int)
//   ft_printf("%u", 0);
//   //    0) -->k<--
//   //    1) -->0<--

// //178 (unsigned int)
//   ft_printf("%u", 1);
//   //    0) -->k<--
//   //    1) -->1<--

// //179 (unsigned int)
//   ft_printf("%u", -1);
//   //    0) -->k<--
//   //   10) -->4294967295<--

// //180 (unsigned int)
//   ft_printf("%u", 4294967295);
//   //    0) -->k<--
//   //   10) -->4294967295<--

// //181 (unsigned int)
//   ft_printf("%u", 4294967296);
//   //    0) -->k<--
//   //    1) -->0<--

// //182 (unsigned int)
//   ft_printf("%5u", 4294967295);
//   //    5) -->     k<--
//   //   10) -->4294967295<--

// //183 (unsigned int)
//   ft_printf("%15u", 4294967295);
//   //   15) -->               k<--
//   //   15) -->     4294967295<--

// //184 (unsigned int)
//   ft_printf("%-15u", 4294967295);
//   //   15) -->               k<--
//   //   15) -->4294967295     <--

// //185 (unsigned int)
//   ft_printf("%015u", 4294967295);
//   //   15) -->000000000000000k<--
//   //   15) -->000004294967295<--

// //186 (unsigned int)
//   ft_printf("% u", 4294967295);
//   //    0) -->k<--
//   //   10) -->4294967295<--

// //187 (unsigned int)
//   ft_printf("%+u", 4294967295);
//   //    1) -->uk<--
//   //   10) -->4294967295<--

// //188 (unsigned long)
//   ft_printf("%lu", 4294967295);
//   //   10) -->4294967295k<--
//   //   10) -->4294967295<--

// //189 (unsigned long)
//   ft_printf("%lu", 4294967296);
//   //   10) -->4294967296k<--
//   //   10) -->4294967296<--

// //190 (unsigned long)
//   ft_printf("%lu", -42);
//   //    3) -->-42k<--
//   //   20) -->18446744073709551574<--

// //191 (unsigned long long)
//   ft_printf("%llu", 4999999999);
//   //    0) -->k<--
//   //   10) -->4999999999<--

// //192 (intmax_t)
//   ft_printf("%ju", 4999999999);
//   //    0) -->k<--
//   //   10) -->4999999999<--

// //193 (size_t)
//   ft_printf("%ju", 4294967296);
//   //    0) -->k<--
//   //   10) -->4294967296<--

// //194 (unsigned long)
//   ft_printf("%U", 4294967295);
//   //    0) -->k<--
//   //   10) -->4294967295<--

// //195 (unsigned long)
//   ft_printf("%hU", 4294967296);
//   //    0) -->k<--
//   //   10) -->4294967296<--

// //196 (unsigned long)
//   ft_printf("%U", 4294967296);
//   //    0) -->k<--
//   //   10) -->4294967296<--
// // getchar();
// //197 (unsigned int)
//   ft_printf("@moulitest: %.5u", 42);
//     // 17) -->@moulitest:      k<--
//     // 17) -->@moulitest: 00042<--

// //--------------
// }
