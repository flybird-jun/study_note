function drawClockBackground(ctx,x,y,weigh,height)
{
	ctx.save();//开始前保存画布状态
	var oldStokeStyle = ctx.strokeStyle;
	ctx.stokeStyle = "black";
	var dx = (x+weigh)/2;
	var dy = (y+height)/2;
	
	ctx.lineWidth = 7;
	ctx.translate(dx,dy);
	
	ctx.fillStyle = "black";
	ctx.beginPath();
	ctx.arc(0, 0,3, 0, 2 * Math.PI, false);
	ctx.fill();
	//画外圆
	ctx.beginPath();
	var radious = ((weigh>height?weigh:height)-ctx.lineWidth)/2;
	
	ctx.arc(0, 0,radious, 0, 2 * Math.PI, false);
	ctx.stroke();
	
	var pointCycleWidth = 16;
	
	//画刻度,每格6度
	var pointWidth = 3;
	var pointWWidth = 5;
	var pointRad = radious - ctx.lineWidth/2 - pointCycleWidth/2;
	for(var i = 0;i<60;i++)
	{
		var w ;
		if(i%5==0)
		{
			w = pointWWidth;
			ctx.fillStyle = "black";
		}
		else
		{
			w = pointWidth;
			ctx.fillStyle = "gray";
		}
		var dx = pointRad*Math.cos(i*Math.PI/30);//i*6/360*2*Math.PI
		var dy = pointRad*Math.sin(i*Math.PI/30);
		//ctx.fillRect(dx,dy,w,w);
			ctx.beginPath();
		ctx.arc(dx, dy,w, 0, 2 * Math.PI, false);
		ctx.fill();
	}
	
	
	//画数字
	ctx.textAlign = "center";
	ctx.textBaseline = "middle";
	ctx.font = "20px 宋体";
	var numberRad = radious-pointCycleWidth - 20/2;
	
	ctx.fillStyle = "black";
	for(var i = 0 ;i<12;i++)
	{
		var text = i+3;//0度对应的是3点
		if(text>12)
		{
			text = text - 12;
		}
		var rad = i*30;
		var dx = Math.cos(rad/180*Math.PI)*(numberRad);
		var dy = Math.sin(rad/180*Math.PI)*(numberRad);
		ctx.fillText(text,dx,dy);
	}
	
	ctx.translate(x,y);//恢复原坐标原点
	ctx.restore();
	return numberRad - 20/2;
}
function TimeRect(color,width,height)
{
	this.angle = null;
	this.color = color;
	this.width = width;
	this.height = height;
	this.draw = function(ctx)
				{
					ctx.save();
					ctx.rotate(this.angle/180.0*Math.PI);
					//ctx.rotate(30/180.0*Math.PI);
					ctx.fillStyle = this.color;
					ctx.fillRect(0,0,this.width,this.height);
					ctx.restore();					
				}
}
function drawTime(ctx,x,y,weigh,height,rad)
{
	var obj = new Date();
	var hour = obj.getHours();
	var min = obj.getMinutes();
	var sec = obj.getSeconds();
	ctx.save();
	var dx = (x+weigh)/2;
	var dy = (y+height)/2;
	ctx.translate(dx,dy);
	ctx.rotate(Math.PI);//顺时针旋转90，让刻度12保持在0度角
	//时针
	var HourRect = new TimeRect("black",1,80);
	HourRect.angle = hour*30+min*0.5;
	HourRect.draw(ctx);
	//分针
	
	var minRect = new TimeRect("green",1,140);
	minRect.angle = min*6+sec/10.0;
	minRect.draw(ctx);
	//秒针
	var secRect = new TimeRect("red",1,180);
	secRect.angle = sec*6;
	secRect.draw(ctx);
	ctx.translate(x,y);//恢复原坐标原点
	
	ctx.restore();
}

function drawClock(canvas,x,y,weigh,height)
{
	var context = canvas.getContext("2d");
	var rad=drawClockBackground(context,x,y,weigh,height);
	drawTime(context,x,y,weigh,height,rad);
	function goClock()
	{
		//draw
		context.clearRect(x,y,weigh,height);
		drawClock(canvas,x,y,weigh,height);
		setTimeout(goClock,300);
	}
	setTimeout(goClock,300);
/*	setInterval(function()
			{
				context.clearRect(x,y,weigh,height);
				drawClock(canvas,0,0,canvas.width,canvas.height);
			}
	,900);*/
}
window.onload = function(){
	var canvas = document.getElementById("clock");
	if(canvas.getContext)
	{
		drawClock(canvas,0,0,canvas.width,canvas.height);

	}

}