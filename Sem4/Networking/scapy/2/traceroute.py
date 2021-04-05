from scapy.all import *


def traceroute_client():

    TIMEOUT = 6

    hops = list()
    time_to_live = 1
    flag = True

    print('Starting Traceroute...')
    while flag:

        
        data_pkt = sr1(IP(dst="www.google.com", ttl=time_to_live)/ICMP()/'Hello Google', verbose=0, timeout=10)
        print('Packet sent')
        if data_pkt is None:
            print('Timeout Occured!!! Packet is Lost!!!')
            time_to_live = time_to_live + 1
            continue
        if data_pkt[1].type == 11:
            hops.append(data_pkt[0].src)
            print(f"Adding {data_pkt[0].src} to hops list..")
            time_to_live = time_to_live + 1
        else:
            print('Traceroute completed')
            flag = False

    index = 0
    for hop in hops:
        print(f"{index} : {hop}")
        index = index + 1


traceroute_client()
