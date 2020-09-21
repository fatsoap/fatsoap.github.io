function v_post(){
    var div = document.getElementById("post_page");
    var r_button = document.getElementById("postRbtn");
    var l_button = document.getElementById("postLbtn");
    var gallery = document.getElementById("gallery_page");
    if (div.style.display === "none") {
        div.style.display = "block";
        l_button.style.display = "block";
        gallery.style.display = "none";
        r_button.innerText = 'Cancel';        
    } else {
        div.style.display = "none";
        l_button.style.display = "none";
        gallery.style.display = "block";
        r_button.innerText = 'POST';
    }
}

function alert_fail(str){
    alert(str);
}