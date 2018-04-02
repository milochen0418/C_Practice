



/*
The file path that we want to writea
/etc/wpa_supplicant/wpa_supplicant.conf

*/
/*
The file content that we want to write

country=GB
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1

network={
	ssid="ittraining401"
	psk="itstudent"
}
*/

/*
	Purpose
	$ ./mywifi ssid password 
	Then wifi has been changed
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
int main( int argc, char* argv[]) {
	printf("Hello World !! ");
	char file_content[1000]; 
	char file_content_fmt[1000] = "\n\
country=GB\n\
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev\n\
update_config=1\n\
\n\
network={\n\
\tssid=\"%s\"\n\
\tpsk=\"%s\"\n\
}\n\
\0";

	/*
	char ssid[]="ittraining401";
	char psk[]="itstudent";
*/

	char* ssid = argv[1];
	char* psk = argv[2]; 

	sprintf(file_content, file_content_fmt, ssid, psk );
	printf("file content = \n%s", file_content);




	//write file_content into the filepath
	char filepath[] = "./test.conf";
	//char filepath[] = "/etc/wpa_supplicant/wpa_supplicant.conf";
	//After you put files into raspberry pi , use the above path
	FILE * fp = fopen(filepath, "w");
	int file_content_size = strlen(file_content);
	//fwrite(file_content, 1 , sizeof(file_content), fp);
	fwrite(file_content, 1 , file_content_size, fp);
	fclose(fp);
	exit(0);
}


void write_wifi_setting() {

}


