import subprocess
import sys


def get_text(type):
    texts = []
    start = 0
    for i in range(1, 1000):
        try:
            file = open("test{:02d}.{}".format(i, type), "r")
            texts.append("".join(file.readlines()))
            file.close
        except:
            if type == "in":
                if i == 1:
                    return 0, [];
                break
            if i == start + 1:
                start += 1
                texts.append("")
            else:
                break
    return start, texts


def inOutTests(ins, outs, num_of_tests, start, prog_name):
    compiled = subprocess.run(["gcc", "{}.c".format(prog_name)])
    if compiled.returncode != 0:
        print("\nPrevajanje ni uspelo!!!")
        return
    correct = 0
    for i in range(start, num_of_tests):
        proces = subprocess.Popen([r"a.exe"], stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.PIPE, encoding="utf-8")
        received = proces.communicate(input=ins[i])[0]
        out = "Test-{:02d}: {}".format(i + 1, "OK" if received == outs[i] else "FAILED")
        print(out)
        if received != outs[i]:
            print(["expected :", outs[i]])
            print(["got      :", received])
        else:
            correct += 1
    print()
    print("{}/{}: {}%".format(correct, num_of_tests - start, correct/(num_of_tests - start)*100))


def functionTests(outs, num_of_tests, start, prog_name):
    correct = 0
    for i in range(start, num_of_tests):
        compiled = subprocess.run(["gcc", "test{:02d}.c".format(i + 1), "{}.c".format(prog_name), "-lm", "-w"])
        if compiled.returncode != 0:
            continue
        proces = subprocess.Popen([r"a.exe"], stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.PIPE, encoding="utf-8")
        received = proces.communicate()[0]
        out = "Test-{:02d}: {}".format(i + 1, "OK" if received == outs[i] else "FAILED")
        print(out)
        if received != outs[i]:
            print(["expected :", outs[i]])
            print(["got      :", received])
        else:
            correct += 1
    print()
    print("{}/{}: {}%".format(correct, num_of_tests - start, correct/(num_of_tests - start)*100))


def main():
    prog_name = sys.argv[1]
    start, outs = get_text("out")
    num_of_tests = len(outs)
    _, ins = get_text("in")
    if (len(ins) == len(outs)):
        inOutTests(ins, outs, num_of_tests, start, prog_name)
    else:
        functionTests(outs, num_of_tests, start, prog_name)
    

if __name__ == "__main__":
    main()
