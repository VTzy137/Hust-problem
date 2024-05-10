from Crypto.Hash import SHA256
from binascii import a2b_hex, b2a_hex


def getFile(file, sizeNum):
    # Open file for reading as binary data
    f = open(file, 'rb')
    data = f.read()
    f.close()

    # Chunked 1KB
    bytes = len(data)
    blocks = []
    for i in range(0, bytes, sizeNum):
        blocks.append(data[i:i + sizeNum])

    return blocks



if __name__ == '__main__':
    fw = open("data.txt", "w")
    test_file = "hash.txt"
    # test_file = "hash.txt"
    sizeNum = 1024
    blocks = getFile(test_file, sizeNum)
    for i in range(len(blocks) - 1, -1, -1):
        for j in blocks[i]:
            fw.write(str(j) + " ")
