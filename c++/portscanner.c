int main(int argc, char *argv[]){   
    if (argc < 4 )
    {
        printf ("Please insert the server address" " and range of ports to be scanned\n");
        printf ("USAGE: %s IPV4 first_post last_port\n", argv[0]);
        exit(1);
    }

    char tIP[16] = {0};
    strcpy(tIP, argv[1]); 
    char first_port[6] = {0};
    strcpy(first_port, argv[2]);
    char last_port[6] = {0};
    strcpy(last_port, argv[3]);

    port_scanner(tIP, first_port, last_port);
    return 0;
}