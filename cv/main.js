toggleThemeBtn.onclick = () => {
    document.body.classList.toggle("dark");
    toggleThemeBtn.innerText = document.body.classList.contans("dark")
      ? "change color"
      : "change color";
    localStorage.theme = document.body.className || "light";
  };
  
  var slideIndex = 1;
  showSlides(slideIndex);
  
  // Next/previous controls
  function plusSlides(n) {
    showSlides((slideIndex += n));
  }
  
  // Thumbnail image controls
  function currentSlide(n) {
    showSlides((slideIndex = n));
  }
  
  function showSlides(n) {
    var i;
    var slides = document.getElementsByClassName("mySlides");
    var dots = document.getElementsByClassName("dot");
    if (n > slides.length) {
      slideIndex = 1;
    }
    if (n < 1) {
      slideIndex = slides.length;
    }
    for (i = 0; i < slides.length; i++) {
      slides[i].style.display = "none";
    }
    for (i = 0; i < dots.length; i++) {
      dots[i].className = dots[i].className.replace(" active", "");
    }
    slides[slideIndex - 1].style.display = "block";
    dots[slideIndex - 1].className += " active";
  }
  var acc = document.getElementsByClassName("accordion");
  var i;
  
  for (i = 0; i < acc.length; i++) {
    acc[i].addEventListener("click", function () {
      /* Toggle between adding and removing the "active" class,
          to highlight the button that controls the panel */
      this.classList.toggle("active");
  
      /* Toggle between hiding and showing the active panel */
      var panel = this.nextElementSibling;
      if (panel.style.display === "block") {
        panel.style.display = "none";
      } else {
        panel.style.display = "block";
      }
    });
  }





  // znajdź wszystkie przyciski z klasą "accordion" i dodaj do nich nasłuchiwanie zdarzeń
var acc = document.querySelectorAll(".accordion");
for (var i = 0; i < acc.length; i++) {
  acc[i].addEventListener("click", function() {

    // przełącz klasę "active" dla przycisku, aby go obrócić
    this.classList.toggle("active");

    // znajdź panel z sekcją, która ma być wyświetlona lub ukryta
    var panel = this.nextElementSibling;

    // jeśli panel jest ukryty, to go pokaż, a jeśli jest widoczny, to go ukryj
    if (panel.style.display === "block") {
      panel.style.display = "none";
    } else {
      panel.style.display = "block";
    }
  });
}
