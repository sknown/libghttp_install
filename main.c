#include <ghttp.h>
int main(int argc, char *argv[])
{
	char *uri = "http://www.oschina.net/";
	ghttp_request *request = NULL;
	ghttp_status status;
	char *buf;
	int bytes_read;

	request = ghttp_request_new();
	if(ghttp_set_uri(request, uri) == -1)
		exit(-1);
	if(ghttp_set_type(request, ghttp_type_get) == -1)
		exit(-1);
	ghttp_prepare(request);
	status = ghttp_process(request);
	if(status == ghttp_error)
		exit(-1);
	/* OK, done */
	printf("Status code -> %d\n", ghttp_status_code(request));
	buf = ghttp_get_body(request);
	bytes_read = ghttp_get_body_len(request);

	printf("%s\n", buf);
	return 0;
}
