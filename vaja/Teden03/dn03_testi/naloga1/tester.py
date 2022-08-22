import subprocess
import sys


def get_text(type, num_of_tests):
    texts = []
    for i in range(1, num_of_tests + 1):
        try:
            file = open("test{:02d}.{}".format(i, type), "r")
            texts.append("".join(file.readlines()))
            file.close
        except:
            pass
    return texts


def inOutTests(ins, outs, num_of_tests, prog_name):
    compiled = subprocess.run(["gcc", "{}.c".format(prog_name)])
    if compiled.returncode != 0:
        print("\nPrevajanje ni uspelo!!!")
        return
    correct = 0
    for i in range(num_of_tests):
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
    print("{}/{}: {}%".format(correct, num_of_tests, correct/num_of_tests*100))


def functionTests(outs, num_of_tests, prog_name):
    correct = 0
    for i in range(num_of_tests):
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
    print("{}/{}: {}%".format(correct, num_of_tests, correct/num_of_tests*100))



def main():
    num_of_tests = 10
    prog_name = sys.argv[1]
    ins = get_text("in", num_of_tests)
    outs = get_text("out", num_of_tests)
    if (len(ins) == len(outs)):
        inOutTests(ins, outs, num_of_tests, prog_name)
    else:
        functionTests(outs, num_of_tests, prog_name)
    

if __name__ == "__main__":
    main()
