class TestWebComponent extends HTMLElement {
  static get observedAttributes(){
    return ['title','subtitle','theme', 'component-number-id']
  }
  constructor() {
    super();
    this.shadow = this.attachShadow({ mode: 'open' });
    this.shadow.innerHTML = `
      <p>Hello from my custom web component!!</p>
    `;
    this.heading = this.shadow.appendChild(document.createElement('h2'))
    this.heading.innerText = ''
    this.subHeading = this.shadow.appendChild(document.createElement('h3'))
    this.subHeading.innerText = ''
    this.more = this.shadow.appendChild(document.createElement('div'))
    this.more.innerText='more...'
    this.styles = this.shadow.appendChild(document.createElement('style'))
    this.styles.innerText='p{color: blue}'
    const emitButton = this.shadow.appendChild(document.createElement('button'))
    emitButton.innerText = 'reset'
    emitButton.addEventListener('click', this.reset.bind(this))
    this.componentNumberId = -1;
  }
  runCallback(arg){
    const callback = window[`callFromComponent${this.componentNumberId}`]
    callback(arg)
  }
  reset(){
    this.runCallback({data:'Hello Elechka my love', command:'reset'})
  }
  attributeChangedCallback(name, oldValue, newValue){
    console.log({name, oldValue, newValue})
    if(name=='title'){
      this.setTitle(newValue)
    }
    if(name=='subtitle'){
      this.setSubtitle(newValue)
    }
    if(name=='theme'){
      this.setTheme(newValue)
    }
    if(name=='component-number-id'){
      this.setComponentNumberId(newValue)
    }
  }
  setTitle(value){
    this.heading.innerText = value;
  }
  setSubtitle(value){
    this.subHeading.innerText = value;
  }
  setComponentNumberId(value){
    this.componentNumberId = value;
  }
  setTheme(value){
    switch (value){
      case 'green':this.styles.innerText = 'p{color:#008700;}'; break;
      case 'red':this.styles.innerText = 'p{color:#cd0909;}'; break;
      case 'blue':this.styles.innerText = 'p{color:#0909F0;}'; break;
    }
  }
}
customElements.define('test-web-component', TestWebComponent);
