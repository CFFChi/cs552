#define MAJOR_NUM 155

#define RD_MALLOC _IOR(MAJOR_NUM, 0, int)
#define RD_CREAT _IOR(MAJOR_NUM, 1, char *)
#define RD_MKDIR _IOR(MAJOR_NUM, 2, char *)
#define RD_OPEN _IOR(MAJOR_NUM, 3, char *)
#define RD_CLOSE _IOR(MAJOR_NUM, 4, int) 
#define RD_READ _IOR(MAJOR_NUM, 5, struct Params) //param data structure
#define RD_WRITE _IOR(MAJOR_NUM, 6, struct Params) //param ds
#define RD_LSEEK _IOR(MAJOR_NUM, 7, struct Params) //param ds
#define RD_UNLINK _IOR(MAJOR_NUM, 8, char *)
#define RD_READDIR _IOR(MAJOR_NUM, 9, struct Params) //param ds
