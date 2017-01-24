// cURL http client

#include <curl/curl.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	printf("cURL http client starting\n");

	CURL * curl;


	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.au.dk/");

		curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
		
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		curl_easy_perform(curl);
	}

	return 0;
}