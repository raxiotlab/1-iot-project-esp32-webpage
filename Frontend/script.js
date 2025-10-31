const button = document.getElementById("btn-led");
const statusDiv = document.getElementById("status");

let ledOn = false;

button.addEventListener("click", async () => {
  try {
    ledOn = !ledOn;
    const url = `http://192.168.1.10/led?state=${ledOn ? 1 : 0}`;
    const response = await fetch(url);

    if (!response.ok) throw new Error("Request failed");

    statusDiv.textContent = ledOn ? "LED ON" : "LED OFF";
    button.textContent = ledOn ? "Turn LED Off" : "Turn LED On";
  } catch (err) {
    statusDiv.textContent = "Connection error";
    console.error(err);
  }
});
