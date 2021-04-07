import io
import random
from flask import Flask,Response, render_template
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
from matplotlib.figure import Figure

app = Flask(__name__)
@app.route('/')
def home():
    return render_template("index.html")
@app.route('/plot.png')
def plot_png():
    fig = create_figure()
    output = io.BytesIO()
    FigureCanvas(fig).print_png(output)
    return Response(output.getvalue(), mimetype='image/png')

def create_figure():
    fig = Figure()
    axis = fig.add_subplot(1, 1, 1)
    ys = [random.randint(0, 100) for i in range(100)]
    xs = [i for i in range(100)]
    axis.plot(xs, ys)
    return fig

if __name__ == "__main__":
    app.run(debug=True)