#ifndef LOG_H
#define LOG_H

#define LOG_STR(str) printf("%s:%d:%s = %s\n", __FILE__, __LINE__, #str, (str))
#define LOG_INT(i) printf("%s:%d:%s = %d\n", __FILE__, __LINE__, #i, (i))
#define LOG_DOUBLE(d) printf("%s:%d:%s = %lf\n", __FILE__, __LINE__, #d, (d))

#endif
