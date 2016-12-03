latin = ['\x00' '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c',
         '\x0d', '\x0e', '\x0f',
         '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a', '\x1b', '\x1c',
         '\x1d', '\x1e', '\x1f',
         '\x20', '\x21', '\x22', '\x23', '\x24', '\x25', '\x26', '\x27', '\x28', '\x29', '\x2a', '\x2b', '\x2c',
         '\x2d', '\x2e', '\x2f',
         '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x3a', '\x3b', '\x3c',
         '\x3d', '\x3e', '\x3f',
         '\x40', '\x41', '\x42', '\x43', '\x44', '\x45', '\x46', '\x47', '\x48', '\x49', '\x4a', '\x4b', '\x4c',
         '\x4d', '\x4e', '\x4f',
         '\x50', '\x51', '\x52', '\x53', '\x54', '\x55', '\x56', '\x57', '\x58', '\x59', '\x5a', '\x5b', '\x5c',
         '\x5d', '\x5e', '\x5f',
         '\x60', '\x61', '\x62', '\x63', '\x64', '\x65', '\x66', '\x67', '\x68', '\x69', '\x6a', '\x6b', '\x6c',
         '\x6d', '\x6e', '\x6f',
         '\x70', '\x71', '\x72', '\x73', '\x74', '\x75', '\x76', '\x77', '\x78', '\x79', '\x7a', '\x7b', '\x7c',
         '\x7d', '\x7e', '\x7f',
         '\x80', '\x81', '\x82', '\x83', '\x84', '\x85', '\x86', '\x87', '\x88', '\x89', '\x8a', '\x8b', '\x8c',
         '\x8d', '\x8e', '\x8f',
         '\x90', '\x91', '\x92', '\x93', '\x94', '\x95', '\x96', '\x97', '\x98', '\x99', '\x9a', '\x9b', '\x9c',
         '\x9d', '\x9e', '\x9f',
         '\xa0', '\xa1', '\xa2', '\xa3', '\xa4', '\xa5', '\xa6', '\xa7', '\xa8', '\xa9', '\xaa', '\xab', '\xac',
         '\xad', '\xae', '\xaf',
         '\xb0', '\xb1', '\xb2', '\xb3', '\xb4', '\xb5', '\xb6', '\xb7', '\xb8', '\xb9', '\xba', '\xbb', '\xbc',
         '\xbd', '\xbe', '\xbf',
         '\xc0', '\xc1', '\xc2', '\xc3', '\xc4', '\xc5', '\xc6', '\xc7', '\xc8', '\xc9', '\xca', '\xcb', '\xcc',
         '\xcd', '\xce', '\xcf',
         '\xd0', '\xd1', '\xd2', '\xd3', '\xd4', '\xd5', '\xd6', '\xd7', '\xd8', '\xd9', '\xda', '\xdb', '\xdc',
         '\xdd', '\xde', '\xdf',
         '\xe0', '\xe1', '\xe2', '\xe3', '\xe4', '\xe5', '\xe6', '\xe7', '\xe8', '\xe9', '\xea', '\xeb', '\xec',
         '\xed', '\xee', '\xef',
         '\xf0', '\xf1', '\xf2', '\xf3', '\xf4', '\xf5', '\xf6', '\xf7', '\xf8', '\xf9', '\xfa', '\xfb', '\xfc',
         '\xfd', '\xfe', '\xff']

def newArray(num):
    array = []
    for x in range(num):
        array.append(0)
    return array


def convertToWordArray(string):
    # print(string)
    lMessageLength = len(string)
    # print(lMessageLength)
    lNumberOfWords_temp1 = lMessageLength + 8
    # print(lNumberOfWords_temp1)
    lNumberOfWords_temp2 = (lNumberOfWords_temp1 - (lNumberOfWords_temp1 % 64)) / 64
    # print(lNumberOfWords_temp2)
    lNumberOfWords = int((lNumberOfWords_temp2 + 1) * 16)
    # print(lNumberOfWords)
    lWordArray = newArray(lNumberOfWords - 1)
    lBytePosition = 0
    lByteCount = 0
    while lByteCount < lMessageLength:
        lWordCount = int((lByteCount - (lByteCount % 4)) / 4)
        lBytePosition = (lByteCount % 4) * 8
        # print(string[int(lByteCount)])
        lWordArray[lWordCount] = (lWordArray[lWordCount] | (ord(string[int(lByteCount)]) << lBytePosition))
        lByteCount += 1
    lWordCount = int((lByteCount - (lByteCount % 4)) / 4)
    lBytePosition = (lByteCount % 4) * 8
    lWordArray[lWordCount] = lWordArray[lWordCount] | (0x80 << lBytePosition)
    lWordArray[lNumberOfWords - 2] = lMessageLength << 3
    lWordArray.append(lMessageLength >> 29)
    return lWordArray


def F(x, y, z):
    #print(x, y, x)
    return (x & y) | ((~x) & z)


def G(x, y, z):
    return (x & z) | (y & (~z))


def H(x, y, z):
    return x ^ y ^ z


def I(x, y, z):
    return y ^ (x | (~z))


def XX(func, a, b, c, d, x, s, ac):
    res = 0
    res = res + a + func(b, c, d)
    res += x
    res += ac
    res = res & 0xffffffff
    res = rol(res, s)
    res = res & 0xffffffff
    res += b
    return res & 0xffffffff


def addu(x, y):
    ls = (x & 0xFFFF) + (y & 0xFFFF)
    return (((x >> 16) + (y >> 16))+(ls >> 16)) << 16 | (ls & 0xFFFF)


def rol(v, s):
    return (v << s) | (v >> (32 - s)) & 0xFFFFFFFF


def wordToHex(lValue):
    wordToHexValue = ''
    wordToHexValue_temp = ''
    for lCount in range(4):
        lByte = (lValue >> (lCount * 8)) & 255
        wordToHexValue_temp = "0" + format(lByte, 'x')
        wordToHexValue = wordToHexValue + wordToHexValue_temp[-2:]
    return wordToHexValue


def md5hash(message):
    x = convertToWordArray(message)
    a = 0x67452301
    b = 0xEFCDAB89
    c = 0x98BADCFE
    d = 0x10325476
    xl = len(x)
    j = 0
    while j < xl:
        aa = a
        bb = b
        cc = c
        dd = d
        a = XX(F, a, b, c, d, x[j + 0], 7, 0xD76AA478)
        d = XX(F, d, a, b, c, x[j + 1], 12, 0xE8C7B756)
        c = XX(F, c, d, a, b, x[j + 2], 17, 0x242070DB)
        b = XX(F, b, c, d, a, x[j + 3], 22, 0xC1BDCEEE)

        a = XX(F, a, b, c, d, x[j + 4], 7, 0xF57C0FAF)
        d = XX(F, d, a, b, c, x[j + 5], 12, 0x4787C62A)
        c = XX(F, c, d, a, b, x[j + 6], 17, 0xA8304613)
        b = XX(F, b, c, d, a, x[j + 7], 22, 0xFD469501)

        a = XX(F, a, b, c, d, x[j + 8], 7, 0x698098D8)
        d = XX(F, d, a, b, c, x[j + 9], 12, 0x8B44F7AF)
        c = XX(F, c, d, a, b, x[j + 10], 17, 0xFFFF5BB1)
        b = XX(F, b, c, d, a, x[j + 11], 22, 0x895CD7BE)

        a = XX(F, a, b, c, d, x[j + 12], 7, 0x6B901122)
        d = XX(F, d, a, b, c, x[j + 13], 12, 0xFD987193)
        c = XX(F, c, d, a, b, x[j + 14], 17, 0xA679438E)
        b = XX(F, b, c, d, a, x[j + 15], 22, 0x49B40821)

        a = XX(G, a, b, c, d, x[j + 1], 5, 0xF61E2562)
        d = XX(G, d, a, b, c, x[j + 6], 9, 0xC040B340)
        c = XX(G, c, d, a, b, x[j + 11], 14, 0x265E5A51)
        b = XX(G, b, c, d, a, x[j + 0], 20, 0xE9B6C7AA)

        a = XX(G, a, b, c, d, x[j + 5], 5, 0xD62F105D)
        d = XX(G, d, a, b, c, x[j + 10], 9, 0x2441453)
        c = XX(G, c, d, a, b, x[j + 15], 14, 0xD8A1E681)
        b = XX(G, b, c, d, a, x[j + 4], 20, 0xE7D3FBC8)

        a = XX(G, a, b, c, d, x[j + 9], 5, 0x21E1CDE6)
        d = XX(G, d, a, b, c, x[j + 14], 9, 0xC33707D6)
        c = XX(G, c, d, a, b, x[j + 3], 14, 0xF4D50D87)
        b = XX(G, b, c, d, a, x[j + 8], 20, 0x455A14ED)

        a = XX(G, a, b, c, d, x[j + 13], 5, 0xA9E3E905)
        d = XX(G, d, a, b, c, x[j + 2], 9, 0xFCEFA3F8)
        c = XX(G, c, d, a, b, x[j + 7], 14, 0x676F02D9)
        b = XX(G, b, c, d, a, x[j + 12], 20, 0x8D2A4C8A)

        a = XX(H, a, b, c, d, x[j + 5], 4, 0xFFFA3942)
        d = XX(H, d, a, b, c, x[j + 8], 11, 0x8771F681)
        c = XX(H, c, d, a, b, x[j + 11], 16, 0x6D9D6122)
        b = XX(H, b, c, d, a, x[j + 14], 23, 0xFDE5380C)

        a = XX(H, a, b, c, d, x[j + 1], 4, 0xA4BEEA44)
        d = XX(H, d, a, b, c, x[j + 4], 11, 0x4BDECFA9)
        c = XX(H, c, d, a, b, x[j + 7], 16, 0xF6BB4B60)
        b = XX(H, b, c, d, a, x[j + 10], 23, 0xBEBFBC70)

        a = XX(H, a, b, c, d, x[j + 13], 4, 0x289B7EC6)
        d = XX(H, d, a, b, c, x[j + 0], 11, 0xEAA127FA)
        c = XX(H, c, d, a, b, x[j + 3], 16, 0xD4EF3085)
        b = XX(H, b, c, d, a, x[j + 6], 23, 0x4881D05)

        a = XX(H, a, b, c, d, x[j + 9], 4, 0xD9D4D039)
        d = XX(H, d, a, b, c, x[j + 12], 11, 0xE6DB99E5)
        c = XX(H, c, d, a, b, x[j + 15], 16, 0x1FA27CF8)
        b = XX(H, b, c, d, a, x[j + 2], 23, 0xC4AC5665)

        a = XX(I, a, b, c, d, x[j + 0], 6, 0xF4292244)
        d = XX(I, d, a, b, c, x[j + 7], 10, 0x432AFF97)
        c = XX(I, c, d, a, b, x[j + 14], 15, 0xAB9423A7)
        b = XX(I, b, c, d, a, x[j + 5], 21, 0xFC93A039)

        a = XX(I, a, b, c, d, x[j + 12], 6, 0x655B59C3)
        d = XX(I, d, a, b, c, x[j + 3], 10, 0x8F0CCC92)
        c = XX(I, c, d, a, b, x[j + 10], 15, 0xFFEFF47D)
        b = XX(I, b, c, d, a, x[j + 1], 21, 0x85845DD1)

        a = XX(I, a, b, c, d, x[j + 8], 6, 0x6FA87E4F)
        d = XX(I, d, a, b, c, x[j + 15], 10, 0xFE2CE6E0)
        c = XX(I, c, d, a, b, x[j + 6], 15, 0xA3014314)
        b = XX(I, b, c, d, a, x[j + 13], 21, 0x4E0811A1)

        a = XX(I, a, b, c, d, x[j + 4], 6, 0xF7537E82)
        d = XX(I, d, a, b, c, x[j + 11], 10, 0xBD3AF235)
        c = XX(I, c, d, a, b, x[j + 2], 15, 0x2AD7D2BB)
        b = XX(I, b, c, d, a, x[j + 9], 21, 0xEB86D391)

        a = addu(a, aa)
        b = addu(b, bb)
        c = addu(c, cc)
        d = addu(d, dd)
        j += 16
    return (wordToHex(a) + wordToHex(b) + wordToHex(c) + wordToHex(d)).lower()


def unhexdigest(mystr):
    s = ""
    for i in range(0, len(mystr), 2):
        index = int(mystr[i:i + 2], 16)
        s += latin[index - 1]
    return s