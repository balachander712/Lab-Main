from scapy.all import *
from threading import Thread

import time

TIMEOUT = 6
TIME_LAG = 1


class PayLoad():
    def __init__(self, sequence_number):
        self.command = "MY_PING"
        self.sequence_number = sequence_number
        self.sent_time = time.time()
        self.recv_time = -1

    def __str__(self):
        return f'{self.command} {self.sequence_number} {self.sent_time} {self.recv_time}'


def ping_server(req_count,HOST):
    global data_packets
    for seq_num in range(req_count):
        payload = PayLoad(seq_num)
        data_packets.append(payload)
        pkt = IP(dst=HOST)/ICMP()/str(payload)
        print(payload)
        send(pkt, verbose=0)
        if time.time() - payload.sent_time < 1:
            time.sleep(1 - time.time() + payload.sent_time)

def validate_response(packet):

    global data_packets
    global res_pkt

    if packet[2].type == 0:
        pkt_seq = int(packet[3].load.decode('utf-8').split()[1])
        #print(pkt_seq)
        if 0 <= pkt_seq < 10:
            data_packets[pkt_seq].recv_time = time.time()
            res_pkt.append(str(data_packets[pkt_seq]))


def print_response(packet_count, request_count):
    global res_pkt
    global rtt_list

    for count in range(request_count):
        seq_num = int(packet_count[count].split()[1])

        if data_packets[seq_num].recv_time - data_packets[seq_num].sent_time > 1:
            print(f'{count} Timed Out')
        elif count != seq_num:
            print(f'{seq_num} Recieved Out of Order ')
        else:
            rtt_list.append(data_packets[seq_num].recv_time - data_packets[seq_num].sent_time)
            print(f'{seq_num} {data_packets[count].recv_time} "Successfully Revieved" {(data_packets[seq_num].recv_time - data_packets[seq_num].sent_time) * 1000} ms')
           

if __name__ == '__main__':
    REQUEST_COUNT = 10
    HOST = "www.google.com"

    res_pkt = []
    data_packets = []
    rtt_list = []

    thread = Thread(target=ping_server, args=(REQUEST_COUNT,HOST))
    thread.start()

    recvd = sniff(count=2*REQUEST_COUNT,filter='icmp',prn=validate_response,timeout= REQUEST_COUNT)
    time.sleep(5)

    print_response(res_pkt,REQUEST_COUNT)


    print(f'Average RTT: {sum(rtt_list)/len(rtt_list)} ms.')
    print(f'Percentage of packet loss: {100-((len(rtt_list)/10)*100)} %.')
