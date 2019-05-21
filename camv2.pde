import processing.serial.*;
import processing.video.*;
Serial myPort;
color tracingColor; 
Capture video;
void setup() {
  size(640, 240);
  String portName = Serial.list()[0]; 
   myPort = new Serial(this, portName, 9600);
  String[] cameras = Capture.list();
  printArray(cameras);
  video = new Capture(this, cameras[3]);
  video.start();
  tracingColor = color(255, 0, 0);
}

void captureEvent(Capture video) {
  video.read();
}

void draw() {
  video.loadPixels();
  image(video, 0, 0);
float rec = 400; 
  int closestX = 0;
  int closestY = 0;
for (int x = 0; x < video.width; x++ ) {
  for (int y = 0; y < video.height; y++ ) {
   int loc = x + y * video.width;
   color currentColor = video.pixels[loc];
   float r1 = red(currentColor);
   float g1 = green(currentColor);
   float b1 = blue(currentColor);
   float r2 = red(tracingColor);
   float g2 = green(tracingColor);
   float b2 = blue(tracingColor);
   float d = dist(r1, g1, b1, r2, g2, b2); 
if (d < rec) {
        rec = d;
        closestX = x;
        closestY = y;
        myPort.write('1');
      }
else {
  myPort.write('0');
}
    }
  }
if (rec < 10) { 
    fill(tracingColor);
    strokeWeight(4.0);
    stroke(0);
    ellipse(closestX, closestY, 16, 16);
  }
}

void mousePressed() {
  int loc = mouseX + mouseY*video.width;
  tracingColor = video.pixels[loc];
}