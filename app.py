import io
# import pyrebase
import random
from flask import Flask,Response, render_template
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
from matplotlib.figure import Figure

# config={
#     "apiKey": "AIzaSyB1ka_mJvweWWDEDeOzvKPZ2Y1ydbVVk58",
#     "authDomain": "test-b5397.firebaseapp.com",
#     "databaseURL": "https://test-b5397-default-rtdb.firebaseio.com",
#     "projectId": "test-b5397",
#     "storageBucket": "test-b5397.appspot.com",
#     "messagingSenderId": "603558314359",
#     "appId": "1:603558314359:web:5f651d283ac168ce972172",
#     "measurementId": "G-SGWRCHF03D"
# }
# firebase = pyrebase.initialize_app(config)
# db = firebase.database()
# info = db.child("Test").child("Data").get().val()
# temp=[]
# humid=[]
# for i in info.items():
#     temp.append(i[1]["temp"])
#     humid.append(i[1]["humid"])

app = Flask(__name__)

@app.route('/')
def home():
    return render_template("index.html", latest_temp = 35, latest_humid = 65)
    
@app.route('/plot.png')
def plot_png():
    fig = create_figure()
    output = io.BytesIO()
    FigureCanvas(fig).print_png(output)
    return Response(output.getvalue(), mimetype = 'image/png')

def create_figure():
    fig = Figure()
    axis = fig.add_subplot(1, 1, 1)
    ys = [i for i in range(100)]
    xs = [i for i in range(100)]
    axis.plot(xs, ys)
    return fig

@app.route('/tempreture')
def tempreture():
    info = [7,22,2,12,1,2,423,42,1,1,423,255,21,3,12]
    return render_template("tempreture.html", temp = info)

@app.route('/humidity')
def humidity():
    info = [7,22,2,12,1,255,21,3,12]
    return render_template("humidity.html", humid = info)

if __name__ == "__main__":
    app.run(debug=True)