import io
import pyrebase
import random
from flask import Flask,Response, render_template
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
from matplotlib.figure import Figure

temp=[]
humid=[]

config={
    "apiKey": "AIzaSyB1ka_mJvweWWDEDeOzvKPZ2Y1ydbVVk58",
    "authDomain": "test-b5397.firebaseapp.com",
    "databaseURL": "https://test-b5397-default-rtdb.firebaseio.com",
    "projectId": "test-b5397",
    "storageBucket": "test-b5397.appspot.com",
    "messagingSenderId": "603558314359",
    "appId": "1:603558314359:web:5f651d283ac168ce972172",
    "measurementId": "G-SGWRCHF03D"
}
firebase = pyrebase.initialize_app(config)
db = firebase.database()


app = Flask(__name__)

@app.route('/')
def home():
    global temp, humid
    
    # Get info stored in rtdb
    info = db.child("Test").child("Data").get().val()
    
    temp=[]
    humid=[]

    # Extract temp and humidity from info
    for i in info.items():
        temp.append(i[1]["Temperature"])
        humid.append(i[1]["Humidity"])

    fire=(temp[-1]+temp[-2]+temp[-3]+temp[-4]+temp[-5])/5
    
    temp.reverse()
    humid.reverse()
    temp = temp[: min(12, len(temp))]
    humid = humid[: min(12, len(humid))]
    labels = [i for i in range(1, len(temp)+1)]
    # render 'index.html'
    # latest_tem and latest_humid are passed to html page to show the latest values
    return render_template("index.html", latest_temp = temp[0], latest_humid = humid[0], temp_list = temp, humid_list = humid,
                            temp=temp,humid=humid, labels = labels,fire=fire)

if __name__ == "__main__":
    app.run(debug=True)