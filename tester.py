import subprocess


def get_text(type, num_of_tests):
    texts = []
    for i in range(1, num_of_tests + 1):
        file = open("test{:02d}.{}".format(i, type), "r")
        texts.append("".join(file.readlines()))
        file.close
    return texts


def main():
    num_of_tests = 10
    ins = get_text("in", num_of_tests)
    outs = get_text("out", num_of_tests)
    for i in range(num_of_tests):
        proces = subprocess.Popen([r"a.exe"], stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.PIPE, encoding="utf-8")
        received = proces.communicate(input=ins[i])[0]
        out = "Test-{:02d}: {}".format(i + 1, "OK" if received == outs[i] else "FAILED")
        print(out)
        if received != outs[i]:
            print(["expected :", outs[i]])
            print(["got      :", received])


if __name__ == "__main__":
    main()
