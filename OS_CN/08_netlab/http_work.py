import requests


def write_to_file(filename, content):
    with open(filename, "a") as file:
        file.truncate(0)
        file.write(str(content))


def main():

    g = requests.get("https://httpbin.org/get")
    write_to_file("get/status_code.txt", g.status_code)
    write_to_file("get/headers.txt", g.headers)
    write_to_file("get/content.txt", g.text)
    write_to_file("get/request_headers.txt", g.request.headers)
    write_to_file("get/request_body.txt", g.request.body)

    o = requests.options("https://httpbin.org/")
    write_to_file("options/status_code.txt", o.status_code)
    write_to_file("options/headers.txt", o.headers)
    write_to_file("options/content.txt", o.text)

    p = requests.post("https://httpbin.org/post", data={'a': 1})
    write_to_file("post/status_code.txt", p.status_code)
    write_to_file("post/headers.txt", p.headers)
    write_to_file("post/content.txt", p.text)
    write_to_file("post/request_headers.txt", p.request.headers)
    write_to_file("post/request_body.txt", p.request.body)


if __name__ == "__main__":
    main()
