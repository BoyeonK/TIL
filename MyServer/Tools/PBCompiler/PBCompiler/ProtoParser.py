
class ProtoParser():
    def __init__(self, start_id, S_prefix, C_prefix):
        self.S_pkt = []
        self.C_pkt = []
        self.total_pkt = []
        self.start_id = start_id
        self.id = start_id
        self.S_prefix = S_prefix
        self.C_prefix = C_prefix

    def parse_proto(self, path):
        f = open(path, 'r')
        lines = f.readlines()

        for line in lines:
            if line.startswith('message') == False:
                continue
            pkt_name = line.split()[1].upper()
            if pkt_name.startswith(self.S_prefix):
                self.S_pkt.append(Packet(pkt_name, self.id))
            elif pkt_name.startswith(self.C_prefix):
                self.C_pkt.append(Packet(pkt_name, self.id))
            else:
                continue
            self.total_pkt.append(Packet(pkt_name, self.id))
            self.id += 1

        f.close()


class Packet:
    def __init__(self, name, id):
        self.name = name
        self.id = id