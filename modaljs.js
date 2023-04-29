"use strict";
const showModal = document.querySelectorAll(".show-modal");
const hiddenText = document.querySelectorAll(".hidden");
const closeModal = document.querySelector(".close-modal");
const hideText = () => {
  for (let i = 0; i < 2; i++) {
    hiddenText[i].style.display = "none";
  }
};
const showText = () => {
  for (let i = 0; i < 2; i++) {
    hiddenText[i].style.display = "block";
  }
};
closeModal.addEventListener("click", () => {
  hideText();
});
for (let i = 0; i < 3; i++) {
  showModal[i].addEventListener("click", () => {
    showText();
  });
}
hiddenText[1].addEventListener("click", () => {
  hideText();
});
document.addEventListener("keydown", (event) => {
  if (event.key == "Escape") {
    hideText();
  }
});
