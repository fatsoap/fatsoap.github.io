// When the user scrolls down 20px from the top of the document, show the button
window.onscroll = function() {scrollFunction()};

function Display(state){
	var txt = document.getElementById("page_state").innerText;
	if(txt==='Markdown command'){
		document.getElementById("page_state").innerText = 'Linux command';
		document.getElementById("markdown_command").style.display="none";
		document.getElementById("linux_command").style.display="block";
	}else if(txt==='Linux command'){
		document.getElementById("page_state").innerText = 'Markdown command';
		document.getElementById("markdown_command").style.display="block";
		document.getElementById("linux_command").style.display="none";
	}
}



function scrollFunction() {
	var mybutton = document.getElementById("go2topBtn");
	if (document.body.scrollTop > 50 || document.documentElement.scrollTop > 50) {
		mybutton.style.display = "block";
	} else {
		mybutton.style.display = "none";
	}
}

function topFunction(){	
	document.body.scrollTop = 0; // For Safari
	document.documentElement.scrollTop = 0; // For Chrome, Firefox, IE and Opera
}