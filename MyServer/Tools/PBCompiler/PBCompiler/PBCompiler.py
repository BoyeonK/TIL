
import argparse
import jinja2
import ProtoParser

def main():
    arg_parser = argparse.ArgumentParser(description = 'PBCompiler')
    arg_parser.add_argument('--path', type=str, default='C:/Users/tetep/OneDrive/Desktop/TIL/TIL/MyServer/Common/PB.proto', help='input .Proto path')
    arg_parser.add_argument('--output', type=str, default='TestPacketHandler', help='')
    arg_parser.add_argument('--S', type=str, default='S_', help='')
    arg_parser.add_argument('--C', type=str, default='C_', help='')
    args = arg_parser.parse_args()

    parser = ProtoParser.ProtoParser(1000, args.S, args.C)
    parser.parse_proto(args.path)

    return

if __name__ == '__main__':
    main()