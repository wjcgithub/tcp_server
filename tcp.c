/**
 * [main 多线程tcp服务器]
 * @return [description]
 * int socket(int domain, int type, int protocol);
 * int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
 * int listen(int sockfd, int backlog);
 * int accept(int sockfd, struct sockaddr * addr, socklen_t  *addrlen);
 * read, write
 */

#include "apue.h"
#define MAX_LISTEN 10
char buf[100];

int main(){
	struct sockaddr_in server_ip, remote_ip;
	int server_len, remote_len;

	//err 保存错误码, sd保存socket返回值
	int err, sd, ad, errno;

	//使用ipv4, 面向链接的字节流, 0表示通过ipv4和字节流自动匹配协议为 (TCP)
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd == -1){
		printf("create socket failed , errno is %d\n", errno);
		return;
	}

	//bind addr
	//指定协议簇
	server_ip.sin_family = AF_INET;
	//端口需要从主机序转换到网络序
	server_ip.sin_port = htons(5678);
	//主机地址转换到网络地址
	//INADDR_ANY 这个宏为0, 这样的话是为了增加可移植性, 同时会自动的获取主机的网卡获取ip地址
	server_ip.sin_addr.s_addr = htonl(INADDR_ANY);
	memset(server_ip.sin_zero, 0, 8);
	
	//bind
	err = bind(sd, (struct sockaddr *)(&server_ip), sizeof(struct sockaddr));
	if (err == -1)
	{
		//todo errno 哪里来的
		printf("bind error, errno is %d\n", errno);
		close(sd);
		return;
	}

	//listen
	err = listen(sd, MAX_LISTEN);
	if(err == -1){
		printf("listen error, errno is %d\n", errno);
		close(sd);
		return;
	}

	//accept
	remote_len = sizeof(struct sockaddr);
	// printf("%s\n", server_ip.sin_addr.s_addr);
	ad = accept(sd, (struct sockaddr *)(&remote_ip), &remote_len);
	if (ad == -1)
	{
		printf("accept error, errno is %d \n", errno);
		close(sd);
		return;
	}

	//接收客户端信息
	read(ad, buf, 100);
	printf("buf is %s\n", buf);

	close(ad);
	close(sd);

	return 0;
}
