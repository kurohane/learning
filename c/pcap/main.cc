#include <stdio.h>
#include <pcap.h>

int main(int ac, char **av){
	char err[PCAP_ERRBUF_SIZE];

	char *dev = pcap_lookupdev(err);
	if (!dev) {
		printf("%x %s\n", __LINE__, err);
		return 0;
	} else {
		printf("Device: %s\n", dev);
	}

	bpf_u_int32 net, mask;
	if (pcap_lookupnet(dev, &net, &mask, err) < 0) {
		printf("%x %s\n", __LINE__, err);
		return 0;
	}

	pcap_t *h = pcap_open_live(av[1], BUFSIZ, 1, 0, err);
	if (!h) {
		printf("%x %s\n", __LINE__, err);
		return 0;
	}

	bpf_program fp;
	char filter_exp[] = "port 80";
	if (pcap_compile(h, &fp, filter_exp, 0, net) < 0) {
		printf("%x %s\n", __LINE__, err);
		return 0;
	}

	if (pcap_setfilter(h, &fp) < 0) {
		printf("%x %s\n", __LINE__, err);
		return 0;
	}

	pcap_pkthdr head;
	u_char const *packet = pcap_next(h, &head);
	printf("packets %d\n", head.len);
	printf("%s", packet);
	pcap_close(h);
}

