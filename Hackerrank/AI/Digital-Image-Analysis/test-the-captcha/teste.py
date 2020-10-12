import os

directory = '/home/murillo/anaconda3/git/Hackerrank-Artificial-Intelligence/Digital-Image-Analysis/sampleCaptchas/input'
limit = 4

with open("input.txt", "w") as w:
    start = 1
    for f in sorted(os.listdir(directory)):
        if start <= limit:
            if os.path.isfile(os.path.join(directory, f)):
                filename = "{}/{}".format(directory, f)
                print(filename)
                if os.path.splitext(filename)[1][1:] in 'txt':
                    with open(filename, "r") as f:
                        next(f)
                        pixels = []
                        for line in f:
                            for item in line.split(" "):
                                vals = [int(val) for val in item.split(",")]
                                pixels.append(sum(vals)/len(vals))
                        w.write(str(pixels) + ",")
                        start = start + 1

directory = '/home/murillo/anaconda3/git/Hackerrank-Artificial-Intelligence/Digital-Image-Analysis/sampleCaptchas/output'
with open("output.txt", "w") as w:
    pixels = []
    start = 1
    for f in sorted(os.listdir(directory)):
        if start <= limit:
            if os.path.isfile(os.path.join(directory, f)):
                filename = "{}/{}".format(directory, f)
                print(filename)
                if os.path.splitext(filename)[1][1:] in 'txt':
                    with open(filename, "r") as f:
                        pixels.append(f.readline().strip())
                        start = start + 1
    w.write(str(pixels))