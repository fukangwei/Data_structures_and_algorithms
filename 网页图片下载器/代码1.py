import urllib.request

response = urllib.request.urlopen("http://placekitten.com.s3.amazonaws.com/homepage-samples/200/287.jpg")
cat_img = response.read()

with open("cat_200_300.jpg", "wb") as f:
    f.write(cat_img)