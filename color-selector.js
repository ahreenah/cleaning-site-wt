class ColorSelectorComponent extends HTMLElement {
  
  static get observedAttributes(){
    return ['component-number-id']
  }

  constructor() {
    super();
    this.shadow = this.attachShadow({ mode: 'open' });
    const blueButton = this.shadow.appendChild(document.createElement('button'))
    blueButton.innerText = 'blue'
    blueButton.addEventListener('click', this.setBlue.bind(this))
    const greenButton = this.shadow.appendChild(document.createElement('button'))
    greenButton.innerText = 'green'
    greenButton.addEventListener('click', this.setGreen.bind(this))
    const redButton = this.shadow.appendChild(document.createElement('button'))
    redButton.innerText = 'red'
    redButton.addEventListener('click', this.setRed.bind(this))

    this.componentNumberId = -1;
  }

  runCallback(arg){
    console.log({componentNumberId: this.componentNumberId})
    const callback = window[`callFromComponent${this.componentNumberId}`]
    console.log({callback})
    callback(arg)
  }

  setBlue(){
    this.runCallback({data:'blue', command:'set-color'})
  }

  setGreen(){
    this.runCallback({data:'green', command:'set-color'})
  }

  setRed(){
    this.runCallback({data:'red', command:'set-color'})
  }

  attributeChangedCallback(name, oldValue, newValue){
    if(name=='component-number-id'){
      this.setComponentNumberId(newValue)
    }
  }

  setComponentNumberId(value){
    this.componentNumberId = value;
  }
}
customElements.define('color-selector', ColorSelectorComponent);
