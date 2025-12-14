import csv

def checksum(data):
    chk = 0
    for c in data:
        chk ^= ord(c)
    return chk

with open("telemetry_data.txt") as infile, open("output.csv", "w", newline="") as outfile:
    writer = csv.writer(outfile)
    writer.writerow(["timestamp","ax","ay","az","gx","gy","gz","alt","temp"])

    for line in infile:
        line = line.strip()
        if not line.startswith("$"):
            continue

        try:
            body, recv_chk = line[1:].split("*")
            if int(recv_chk, 16) == checksum(body):
                values = body.split(",")[1:]
                writer.writerow(values)
                print("VALID:", values)
        except:
            pass
