#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char **argv) {
  CURL *curl;
  CURLcode res;

  struct curl_slist *list = NULL;
 
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a curl handle */ 
  curl = curl_easy_init();
  if(curl) {

    list = curl_slist_append(list, "Authorization: Bearer ya29.Ci8lAwZBcg5TpuxM2rxh07wJPykXzl424eACnrqv3secQBrBgRtDe_XCvE-CUnbHXw");

    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */ 
    curl_easy_setopt(curl, CURLOPT_URL, "https://pubsub.googleapis.com/v1/projects/operations-1324/subscriptions");
    /* Now specify the POST data */ 
    //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "grant_type=daniel&project=curl");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}