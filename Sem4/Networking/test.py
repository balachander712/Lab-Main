from scapy.layers.inet import IP, ICMP, TCP
from scapy.sendrecv import sr1, send, sr, AsyncSniffer
import time

# router ip - 192.168.29.1

def print_details(pkt):
    returned_pkt_time = time.time()
    pkt_payload = pkt[3].load.decode('utf-8').split(' ')

    sent_pkt_time = pkt_payload[2]
    sequence_num = pkt_payload[1]
    received_msg = pkt_payload[0]

    # print(sent_pkt_time)
    # print(returned_pkt_time)

    round_trip_time = returned_pkt_time-float(sent_pkt_time)

    if round_trip_time <= 1:
        print(f'{sequence_num} {returned_pkt_time} {received_msg} Successfully_Received {round_trip_time}' ) 
    else:
        print(f'{sequence_num} Timed Out')


if __name__ == "__main__":

    receiver = AsyncSniffer(prn=print_details, filter=f'src 192.168.29.1 and icmp')
    receiver.start()
    time.sleep(2)

    for i in range(1, 11):
        sent_pkt_time = time.time()
        payload = 'MY_PING ' + str(i) + ' ' + str(sent_pkt_time)
        send(IP(dst="192.168.29.1")/ICMP()/payload )
        time.sleep(1)

    receiver.stop()