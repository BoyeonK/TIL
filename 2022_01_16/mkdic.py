def mkdiction(name, age):
    return {"name": name, "age": age}
def to_str(per):
    return "{}\t{}".format(per["name"], per["age"])

a=mkdiction('kby',29)
b=to_str(a)
print(b)