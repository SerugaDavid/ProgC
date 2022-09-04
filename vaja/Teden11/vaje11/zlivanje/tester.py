import subprocess
import sys
from venv import create


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
    print("{}/{}: {:.2f}%".format(correct, num_of_tests - start, correct/(num_of_tests - start)*100))


def make_main(filename):
    with open(filename, 'r', encoding="utf-8") as file:
        filedata = file.read()
    filedata = filedata.replace("__main__()", "main()")
    with open(filename, 'w', encoding="utf-8") as file:
        file.write(filedata)


def delete_main(filename):
    with open(filename, 'r',encoding="utf-8") as file:
        filedata = file.read()
    filedata = filedata.replace("main()", "__main__()")
    with open(filename, 'w',encoding="utf-8") as file:
        file.write(filedata)



def functionTests(outs, num_of_tests, start, prog_name):
    delete_main("{}.c".format(prog_name))
    correct = 0
    for i in range(start, num_of_tests):
        make_main("test{:02d}.c".format(i + 1))
        compiled = subprocess.run(["gcc", "test{:02d}.c".format(i + 1), "{}.c".format(prog_name), "-lm"])
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
    make_main("{}.c".format(prog_name))
    print("{}/{}: {:.2f}%".format(correct, num_of_tests - start, correct/(num_of_tests - start)*100))


def fileTests(ins, num_of_tests, start, prog_name):
    pass


def main():
    prog_name = sys.argv[1]
    start_o, outs = get_text("out")
    num_of_tests = len(outs)
    start_i, ins = get_text("in")
    if len(ins) == len(outs):
        inOutTests(ins, outs, num_of_tests, start_o, prog_name)
    elif len(ins) < len(outs):
        functionTests(outs, num_of_tests, start_o, prog_name)
    else:
        fileTests(ins, len(ins), start_i, prog_name)
    

if __name__ == "__main__":
    main()
