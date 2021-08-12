import urllib.request

req = urllib.request.Request("http://placekitten.com.s3.amazonaws.com/homepage-samples/200/287.jpg")
response = urllib.request.urlopen(req)
cat_img = response.read()

with open("cat_200_300.jpg", "wb") as f:
    f.write(cat_img)