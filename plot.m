data = Import["/Users/masauer2/urban-doodle/output.txt", "Table"]
data = Drop[data,1];
totalenergy = data[[All,3]];
time = data[[All,6]];
plot1 = ListPlot[Transpose@{y,x}, PlotRange->{0,2}, AxesLabel->{"Time", "Total Energy"}, PlotLabel->"Total Energy v Time"]; (*Total Energy v Time*)
plot2 = ListPlot[Transpose@{data[[All,6]],data[[All,2]]}, PlotLabel->"Kinetic Energy v Time"]; (*Kinetic Energy v Time*)
plot3 = ListPlot[Transpose@{data[[All,6]],data[[All,1]]}, PlotLabel->"Potential Energy v Time"];(*Potential Energy v Time*)
Export["/Users/masauer2/urban-doodle/total.jpg",plot1]
Export["/Users/masauer2/urban-doodle/potential.jpg",plot2]
Export["/Users/masauer2/urban-doodle/kinetic.jpg",plot3]




