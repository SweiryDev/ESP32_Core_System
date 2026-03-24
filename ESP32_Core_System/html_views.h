#ifndef HTML_VIEWS_H
#define HTML_VIEWS_H

// Core System Dashboard (Root: "/")

const char* dashboard_html = R"rawliteral(
<!DOCTYPE html>
<html class="dark" lang="en">
<head>
<meta charset="utf-8"/>
<meta content="width=device-width, initial-scale=1.0" name="viewport"/>
<title>ESP32_CORE_SYSTEM</title>
<script src="https://cdn.tailwindcss.com"></script>
<style>
    body { background-color: #0e0e0e; color: #e2e2e2; font-family: monospace; }
    .nav-card { background-color: #1f1f1f; border: 1px solid #353535; transition: all 0.2s; }
    .nav-card:hover { border-color: #00daf3; box-shadow: 0 0 15px rgba(0, 218, 243, 0.1); transform: translateY(-2px); }
    .no-select { user-select: none; -webkit-user-select: none; }
</style>
</head>
<body class="min-h-screen flex flex-col items-center justify-center p-6 no-select">
    <div class="w-full max-w-3xl flex flex-col items-center">
        <div class="mb-12 text-center">
            <h1 class="text-3xl md:text-4xl font-bold tracking-[0.3em] uppercase text-[#00daf3] mb-2 drop-shadow-[0_0_10px_rgba(0,218,243,0.5)]">Core System</h1>
            <p class="text-[#474747] text-xs md:text-sm tracking-widest uppercase font-bold mt-3">ESP32-S3 Multi-Core Operating Environment</p>
        </div>

        <div class="grid grid-cols-1 md:grid-cols-2 gap-6 w-full">
            
            <a href="/matrix" class="nav-card p-6 rounded-lg flex flex-col gap-4 cursor-pointer group outline-none">
                <div class="flex items-center justify-between">
                    <h2 class="text-lg font-bold tracking-widest uppercase group-hover:text-[#00daf3] transition-colors">Matrix Operator</h2>
                    <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="currentColor" class="text-[#474747] group-hover:text-[#00daf3] transition-colors" viewBox="0 0 16 16"><path d="M1 2.5A1.5 1.5 0 0 1 2.5 1h3A1.5 1.5 0 0 1 7 2.5v3A1.5 1.5 0 0 1 5.5 7h-3A1.5 1.5 0 0 1 1 5.5v-3zM2.5 2a.5.5 0 0 0-.5.5v3a.5.5 0 0 0 .5.5h3a.5.5 0 0 0 .5-.5v-3a.5.5 0 0 0-.5-.5h-3zm6.5.5A1.5 1.5 0 0 1 10.5 1h3A1.5 1.5 0 0 1 15 2.5v3A1.5 1.5 0 0 1 13.5 7h-3A1.5 1.5 0 0 1 9 5.5v-3zm1.5-.5a.5.5 0 0 0-.5.5v3a.5.5 0 0 0 .5.5h3a.5.5 0 0 0 .5-.5v-3a.5.5 0 0 0-.5-.5h-3zM1 10.5A1.5 1.5 0 0 1 2.5 9h3A1.5 1.5 0 0 1 7 10.5v3A1.5 1.5 0 0 1 5.5 15h-3A1.5 1.5 0 0 1 1 13.5v-3zm1.5-.5a.5.5 0 0 0-.5.5v3a.5.5 0 0 0 .5.5h3a.5.5 0 0 0 .5-.5v-3a.5.5 0 0 0-.5-.5h-3zm6.5.5A1.5 1.5 0 0 1 10.5 9h3a1.5 1.5 0 0 1 1.5 1.5v3a1.5 1.5 0 0 1-1.5 1.5h-3A1.5 1.5 0 0 1 9 13.5v-3zm1.5-.5a.5.5 0 0 0-.5.5v3a.5.5 0 0 0 .5.5h3a.5.5 0 0 0 .5-.5v-3a.5.5 0 0 0-.5-.5h-3z"/></svg>
                </div>
                <p class="text-xs text-[#888] leading-relaxed font-sans">Direct hardware control interface for the 8x8 WS2812B NeoPixel matrix. Features live drawing, multi-core animations, and preset gallery.</p>
                <div class="mt-auto pt-4 flex items-center gap-2 text-[10px] text-[#00daf3] font-bold tracking-widest uppercase">
                    <span class="w-2 h-2 rounded-full bg-[#00daf3] animate-pulse"></span>
                    Module Online
                </div>
            </a>

            <a href="https://github.com/SweiryDev" target="_blank" class="nav-card p-6 rounded-lg flex flex-col gap-4 cursor-pointer group outline-none">
                <div class="flex items-center justify-between">
                    <h2 class="text-lg font-bold tracking-widest uppercase group-hover:text-white transition-colors">GitHub Repo</h2>
                    <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="currentColor" class="text-[#474747] group-hover:text-white transition-colors" viewBox="0 0 16 16"><path d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.012 8.012 0 0 0 16 8c0-4.42-3.58-8-8-8z"/></svg>
                </div>
                <p class="text-xs text-[#888] leading-relaxed font-sans">View the source code, hardware architecture, and documentation for this project.</p>
                <div class="mt-auto pt-4 flex items-center gap-2 text-[10px] text-[#474747] font-bold tracking-widest uppercase">
                    <span class="w-2 h-2 rounded-full bg-[#474747]"></span>
                    External Link
                </div>
            </a>
        </div>

        <div class="mt-12 text-[#474747] text-[10px] tracking-[0.2em] font-bold flex flex-col items-center gap-2">
            <div>SYSTEM OPERATIONAL</div>
            <div class="text-[#888]">HARDWARE UPTIME: <span id="uptime" class="text-[#00daf3]">00:00:00</span></div>
        </div>
    </div>

    <script>
        // The ESP32 backend will inject the exact boot time in seconds here
        let seconds = %UPTIME%; 
        
        function formatTime() {
            const h = Math.floor(seconds / 3600).toString().padStart(2, '0');
            const m = Math.floor((seconds % 3600) / 60).toString().padStart(2, '0');
            const s = (seconds % 60).toString().padStart(2, '0');
            document.getElementById('uptime').textContent = `${h}:${m}:${s}`;
        }
        
        formatTime(); // Run immediately on load
        
        setInterval(() => {
            seconds++;
            formatTime();
        }, 1000);
    </script>
</body>
</html>
)rawliteral";



// Matrix Operator Interface (Route: "/matrix")

const char* matrix_operator_html = R"rawliteral(
<!DOCTYPE html>
<html class="dark" lang="en">
<head>
<meta charset="utf-8"/>
<meta content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" name="viewport"/>
<title>MATRIX_OPERATOR_V12</title>
<script src="https://cdn.tailwindcss.com"></script>
<style>
    body { background-color: #0e0e0e; color: #e2e2e2; font-family: monospace; overscroll-behavior-y: contain; }
    .matrix-grid { display: grid; grid-template-columns: repeat(8, 1fr); aspect-ratio: 1 / 1; touch-action: none; }
    .matrix-cell { background-color: #000000; border: 1px solid #1f1f1f; cursor: crosshair; transition: opacity 0.1s; }
    .no-select { user-select: none; -webkit-user-select: none; }
    
    input[type="color"] { -webkit-appearance: none; border: none; width: 100%; height: 100%; border-radius: 4px; overflow: hidden; }
    input[type="color"]::-webkit-color-swatch-wrapper { padding: 0; }
    input[type="color"]::-webkit-color-swatch { border: none; }
    .toggle-checkbox:checked { right: 0; border-color: #00daf3; }
    .toggle-checkbox:checked + .toggle-label { background-color: #00daf3; }
    
    .scrollbar-hide::-webkit-scrollbar { display: none; }
    .scrollbar-hide { -ms-overflow-style: none; scrollbar-width: none; }
    .gallery-drag { cursor: grab; }
    .gallery-drag:active { cursor: grabbing; }
    
    .modal-enter { animation: fadeIn 0.2s ease-out forwards; }
    @keyframes fadeIn { from { opacity: 0; transform: scale(0.95); } to { opacity: 1; transform: scale(1); } }
</style>
</head>
<body class="min-h-screen flex flex-col items-center justify-start p-4 no-select pb-12 overflow-x-hidden">

    <div class="w-full max-w-md flex items-center justify-between mb-4 mt-4">
        <a href="/" class="text-[9px] font-bold tracking-widest uppercase text-[#474747] hover:text-[#00daf3] transition-colors flex items-center gap-1 active:scale-95">
            <svg xmlns="http://www.w3.org/2000/svg" width="12" height="12" fill="currentColor" viewBox="0 0 16 16"><path fill-rule="evenodd" d="M15 8a.5.5 0 0 0-.5-.5H2.707l3.147-3.146a.5.5 0 1 0-.708-.708l-4 4a.5.5 0 0 0 0 .708l4 4a.5.5 0 0 0 .708-.708L2.707 8.5H14.5A.5.5 0 0 0 15 8z"/></svg>
            BACK
        </a>
        <h1 class="text-xl font-bold tracking-widest uppercase text-[#00daf3]">Matrix Operator</h1>
        <div class="w-12"></div> </div>
    <div class="flex flex-col gap-3 w-full max-w-md bg-[#1f1f1f] p-3 rounded mb-4 shadow-lg border border-[#353535]">
        <div class="flex gap-4 items-center">
            <div class="flex flex-col items-center">
                <label class="font-bold uppercase tracking-widest text-[9px] mb-1 text-outline-variant">Custom</label>
                <div class="w-10 h-8 border-2 border-[#474747] rounded hover:border-[#00daf3] transition-colors">
                    <input type="color" id="color-picker" value="#ff0000" class="cursor-pointer">
                </div>
            </div>
            
            <div class="h-8 w-px bg-[#353535] mx-1"></div>
            
            <div class="flex flex-col flex-1 overflow-hidden">
                <label class="font-bold uppercase tracking-widest text-[9px] mb-1 text-outline-variant">Base Colors</label>
                <div class="flex gap-2">
                    <button class="quick-color flex-shrink-0 w-8 h-8 rounded bg-[#ff0000] border border-[#ffffff33] hover:scale-110 transition-transform" data-hex="#ff0000"></button>
                    <button class="quick-color flex-shrink-0 w-8 h-8 rounded bg-[#00ff00] border border-[#ffffff33] hover:scale-110 transition-transform" data-hex="#00ff00"></button>
                    <button class="quick-color flex-shrink-0 w-8 h-8 rounded bg-[#0000ff] border border-[#ffffff33] hover:scale-110 transition-transform" data-hex="#0000ff"></button>
                    <button class="quick-color flex-shrink-0 w-8 h-8 rounded bg-[#ffff00] border border-[#ffffff33] hover:scale-110 transition-transform" data-hex="#ffff00"></button>
                    <button class="quick-color flex-shrink-0 w-8 h-8 rounded bg-[#ffffff] border border-[#ffffff33] hover:scale-110 transition-transform" data-hex="#ffffff"></button>
                </div>
            </div>
        </div>

        <div class="flex flex-col mt-2">
            <div class="flex justify-between items-center mb-2">
                <label for="brush-brightness" class="font-bold uppercase tracking-widest text-[10px]">
                    Bright: <span id="bri-val" class="text-[#00daf3]">5</span>
                </label>
            </div>
            <div class="flex items-center gap-3 mb-3">
                <button id="bri-minus" class="w-8 h-8 bg-[#2a2a2a] rounded text-white font-bold hover:bg-[#474747] active:scale-95 border border-[#353535]">-</button>
                <input type="range" id="brush-brightness" min="1" max="255" value="5" class="flex-1 accent-[#00daf3]">
                <button id="bri-plus" class="w-8 h-8 bg-[#2a2a2a] rounded text-white font-bold hover:bg-[#474747] active:scale-95 border border-[#353535]">+</button>
            </div>
            <div class="flex gap-2 items-center">
                <span class="text-[9px] uppercase font-bold text-outline-variant mr-1">Presets:</span>
                <button class="bri-preset flex-1 py-1 bg-[#2a2a2a] rounded border border-[#353535] text-white text-[9px] hover:bg-[#00daf3] hover:text-[#0e0e0e] hover:border-[#00daf3] active:scale-95 transition-all font-bold" data-val="1">1</button>
                <button class="bri-preset flex-1 py-1 bg-[#2a2a2a] rounded border border-[#353535] text-white text-[9px] hover:bg-[#00daf3] hover:text-[#0e0e0e] hover:border-[#00daf3] active:scale-95 transition-all font-bold" data-val="3">3</button>
                <button class="bri-preset flex-1 py-1 bg-[#2a2a2a] rounded border border-[#353535] text-white text-[9px] hover:bg-[#00daf3] hover:text-[#0e0e0e] hover:border-[#00daf3] active:scale-95 transition-all font-bold" data-val="5">5</button>
                <button class="bri-preset flex-1 py-1 bg-[#2a2a2a] rounded border border-[#353535] text-white text-[9px] hover:bg-[#00daf3] hover:text-[#0e0e0e] hover:border-[#00daf3] active:scale-95 transition-all font-bold" data-val="10">10</button>
            </div>
        </div>
    </div>

    <div class="flex gap-3 w-full max-w-md mb-4 items-center">
        <button id="eraser-btn" class="flex-1 py-2 bg-[#2a2a2a] text-white border border-[#474747] font-bold tracking-widest uppercase text-xs hover:bg-[#474747] active:scale-95 rounded transition-all">Eraser</button>
        <button id="clear-btn" class="flex-1 py-2 border border-[#800000] text-[#ffb4ab] font-bold tracking-widest uppercase text-xs hover:bg-[#800000] hover:text-white active:scale-95 rounded transition-all">Clear</button>
        <button id="open-gallery-btn" class="w-12 h-9 flex items-center justify-center bg-[#1f1f1f] border border-[#474747] text-[#00daf3] rounded hover:bg-[#2a2a2a] active:scale-95 transition-all">
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" viewBox="0 0 16 16"><path d="M4.502 9a1.5 1.5 0 1 0 0-3 1.5 1.5 0 0 0 0 3z"/><path d="M14.002 13a2 2 0 0 1-2 2h-10a2 2 0 0 1-2-2V5A2 2 0 0 1 2 3a2 2 0 0 1 2-2h10a2 2 0 0 1 2 2v8a2 2 0 0 1-1.998 2zM14 2H4a1 1 0 0 0-1 1h9.002a2 2 0 0 1 2 2v7A1 1 0 0 0 15 11V3a1 1 0 0 0-1-1zM2.002 4a1 1 0 0 0-1 1v8l2.646-2.354a.5.5 0 0 1 .63-.062l2.66 1.773 3.71-3.71a.5.5 0 0 1 .577-.094l1.777 1.947V5a1 1 0 0 0-1-1h-10z"/></svg>
        </button>
        <div class="flex flex-col items-center ml-1">
            <div class="relative inline-block w-10 align-middle select-none transition duration-200">
                <input type="checkbox" id="invert-toggle" class="toggle-checkbox absolute block w-5 h-5 rounded-full bg-white border-4 appearance-none cursor-pointer z-10 transition-all duration-300" checked/>
                <label for="invert-toggle" class="toggle-label block overflow-hidden h-5 rounded-full bg-[#353535] cursor-pointer"></label>
            </div>
        </div>
    </div>

    <div class="w-full max-w-md aspect-square bg-[#1f1f1f] p-2 shadow-2xl mb-4 border border-[#353535] rounded-lg">
        <div class="matrix-grid w-full h-full bg-[#000000]" id="grid-canvas"></div>
    </div>

    <div class="w-full max-w-md bg-[#1f1f1f] p-3 rounded shadow-lg border border-[#353535]">
        <div class="flex justify-between items-center mb-2">
            <label class="font-bold uppercase tracking-widest text-[10px] text-outline-variant">Anim Studio</label>
            <span class="text-[10px] font-mono text-[#00daf3]" id="frame-count-txt">Frames: 0</span>
        </div>

        <div class="flex items-center gap-2 mb-3">
            <label class="text-[9px] uppercase font-bold text-outline-variant whitespace-nowrap">Delay (ms):</label>
            <input type="number" id="anim-delay" value="200" min="10" max="2000" class="w-16 bg-[#0e0e0e] text-[#00daf3] border border-[#353535] rounded px-1 text-xs text-center outline-none">
            
            <button id="save-frame-btn" class="flex-1 py-1.5 bg-[#2a2a2a] text-[#00daf3] border border-[#00daf3]/30 font-bold tracking-widest uppercase text-[9px] hover:bg-[#00daf3] hover:text-[#0e0e0e] active:scale-95 transition-all rounded">+ Capture Frame</button>
            <button id="clear-anim-btn" class="px-3 py-1.5 bg-[#353535] text-white rounded hover:bg-[#800000] active:scale-95 transition-all text-[9px] font-bold uppercase">Clear</button>
        </div>

        <button id="play-anim-btn" class="w-full py-2 mb-3 bg-[#2a2a2a] text-white border border-[#474747] font-bold tracking-widest uppercase text-[10px] hover:bg-[#474747] active:scale-95 transition-all rounded opacity-50 cursor-not-allowed">Deploy Custom Sequence</button>

        <label class="font-bold uppercase tracking-widest text-[9px] mb-2 block text-outline-variant border-t border-[#353535] pt-3">Animation Presets (Auto-Plays)</label>
        
        <div class="flex gap-3 overflow-x-auto gallery-drag scrollbar-hide w-full snap-x pb-2 pt-1" id="anim-gallery-container" style="-webkit-overflow-scrolling: touch;">
            </div>
    </div>

    <div id="gallery-modal" class="fixed inset-0 bg-black/80 backdrop-blur-sm z-50 hidden flex-col items-center justify-center p-4">
        <div class="bg-[#1f1f1f] border border-[#353535] rounded-lg shadow-2xl w-full max-w-md flex flex-col max-h-[85vh] modal-enter">
            <div class="flex justify-between items-center p-4 border-b border-[#353535]">
                <h2 class="font-bold uppercase tracking-widest text-xs text-white">Preset Database (52)</h2>
                <button id="close-gallery-btn" class="text-[#0e0e0e] font-bold px-3 py-1 bg-[#00daf3] hover:bg-white rounded active:scale-95 transition-all text-xs tracking-widest">CLOSE</button>
            </div>
            <div class="p-4 overflow-y-auto w-full">
                <div class="grid grid-cols-5 gap-3" id="modal-gallery-container"></div>
            </div>
        </div>
    </div>

<script>
    const grid = document.getElementById('grid-canvas');
    const colorPicker = document.getElementById('color-picker');
    const brightnessSlider = document.getElementById('brush-brightness');
    const briVal = document.getElementById('bri-val');
    const briMinusBtn = document.getElementById('bri-minus');
    const briPlusBtn = document.getElementById('bri-plus');
    const eraserBtn = document.getElementById('eraser-btn');
    const invertToggle = document.getElementById('invert-toggle');
    
    // Animation UI
    const frameCountTxt = document.getElementById('frame-count-txt');
    const animDelayInput = document.getElementById('anim-delay');
    const saveFrameBtn = document.getElementById('save-frame-btn');
    const clearAnimBtn = document.getElementById('clear-anim-btn');
    const playAnimBtn = document.getElementById('play-anim-btn');
    const animGalleryContainer = document.getElementById('anim-gallery-container');
    
    let isDrawing = false;
    let isErasing = false;
    let lastSentBuffer = "";
    let hardwareWarningShown = false;
    let customFramesB64 = []; 

    // --- COLORFUL RGB ANIMATION GENERATORS ---
    const colorfulPresets = {
        'Police': {
            delay: 150, type: 'rgb', frames: [
                Array.from({length: 64}, (_, i) => (i % 8 < 4) ? [1, 0, 0] : [0, 0, 0]),
                Array.from({length: 64}, (_, i) => (i % 8 >= 4) ? [0, 0, 1] : [0, 0, 0])
            ]
        },
        'Traffic': {
            delay: 500, type: 'rgb', frames: [
                Array.from({length: 64}, () => [1, 0, 0]), // Red
                Array.from({length: 64}, () => [1, 1, 0]), // Yellow
                Array.from({length: 64}, () => [0, 1, 0])  // Green
            ]
        },
        'Rainbow': {
            delay: 100, type: 'rgb', frames: Array.from({length: 8}, (_, f) => Array.from({length: 64}, (_, i) => {
                let val = ((i % 8) + f) % 8;
                if (val === 0) return [1, 0, 0];
                if (val === 1) return [1, 0.5, 0];
                if (val === 2) return [1, 1, 0];
                if (val === 3) return [0, 1, 0];
                if (val === 4) return [0, 1, 1];
                if (val === 5) return [0, 0, 1];
                if (val === 6) return [1, 0, 1];
                return [1, 1, 1];
            }))
        },
        'Disco': {
            delay: 100, type: 'rgb', frames: Array.from({length: 8}, () => Array.from({length: 64}, () => [
                Math.random() > 0.5 ? 1 : 0, 
                Math.random() > 0.5 ? 1 : 0, 
                Math.random() > 0.5 ? 1 : 0
            ]))
        },
        'Sparkle': {
            delay: 80, type: 'rgb', frames: Array.from({length: 12}, () => Array.from({length: 64}, () => 
                Math.random() > 0.85 ? [Math.random()>0.5?1:0, Math.random()>0.5?1:0, Math.random()>0.5?1:0] : [0, 0, 0]
            ))
        }
    };

    // --- STANDARD BITMASK ANIMATIONS ---
    const animPresets = {
        'Spin': { delay: 80, frames: [
            [0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18], [0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01],
            [0x00,0x00,0x00,0xff,0xff,0x00,0x00,0x00], [0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80] ] },
        'Pulse': { delay: 150, frames: [
            [0x00,0x66,0x99,0x81,0x42,0x24,0x18,0x00], [0x00,0x00,0x24,0x7e,0x3c,0x18,0x00,0x00] ] },
        'Sweep': { delay: 50, frames: [
            [0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00], [0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00],
            [0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00], [0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00],
            [0x00,0x00,0x00,0x00,0xff,0x00,0x00,0x00], [0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00],
            [0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00], [0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff] ] },
        'Ping': { delay: 100, frames: [
            [0x00,0x00,0x00,0xc0,0xc0,0x00,0x00,0x00], [0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00],
            [0x00,0x00,0x00,0x0c,0x0c,0x00,0x00,0x00], [0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x00],
            [0x00,0x00,0x00,0x0c,0x0c,0x00,0x00,0x00], [0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00] ] },
        'Flash': { delay: 200, frames: [
            [0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff], [0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00] ] },
        ...colorfulPresets
    };

    // Populate Square Animation Gallery
    Object.keys(animPresets).forEach(key => {
        const btn = document.createElement('button');
        btn.className = "flex-shrink-0 snap-start w-16 h-12 flex flex-col justify-center items-center bg-[#2a2a2a] border border-[#353535] rounded-lg hover:border-[#00daf3] hover:text-[#00daf3] active:scale-95 transition-all";
        btn.innerHTML = `<span class="text-[10px] font-bold uppercase tracking-wider">${key}</span>`;
        btn.onclick = () => deployAnimPreset(key);
        animGalleryContainer.appendChild(btn);
    });

    // Deploy Mathematical Anim Preset
    function deployAnimPreset(key) {
        const preset = animPresets[key];
        const hw = calculateHardwareRGB();
        const bri = parseInt(brightnessSlider.value);
        let payloadB64Array = [];

        preset.frames.forEach(frameData => {
            let grid2D = [];
            for (let row = 0; row < 8; row++) {
                let rowArray = [];
                for (let col = 0; col < 8; col++) {
                    if (preset.type === 'rgb') {
                        let p = frameData[row * 8 + col];
                        rowArray.push([Math.round(p[0]*bri), Math.round(p[1]*bri), Math.round(p[2]*bri)]);
                    } else {
                        if ((frameData[row] >> (7 - col)) & 1) rowArray.push([hw.r, hw.g, hw.b]);
                        else rowArray.push([0, 0, 0]);
                    }
                }
                grid2D.push(rowArray);
            }
            let outputGrid = invertToggle.checked ? grid2D.reverse().map(r => r.reverse()) : grid2D;
            const flatBuffer = [];
            outputGrid.forEach(r => r.forEach(rgb => flatBuffer.push(...rgb)));
            
            const bytes = new Uint8Array(flatBuffer);
            let binary = '';
            for (let i = 0; i < bytes.byteLength; i++) binary += String.fromCharCode(bytes[i]);
            payloadB64Array.push(window.btoa(binary));
        });

        const payloadStr = `ANIM:${preset.delay}:${payloadB64Array.join(',')}`;
        
        // FORCING BUFFER RESET SO SUBSEQUENT "CLEARS" WORK IMMEDIATELY
        lastSentBuffer = ""; 
        
        fetch('/anim', { method: 'POST', body: payloadStr }).catch(err => console.error(err));
    }

    // --- CUSTOM ANIMATION STUDIO LOGIC ---
    function updateAnimUI() {
        frameCountTxt.textContent = `Frames: ${customFramesB64.length}`;
        if (customFramesB64.length > 0) {
            playAnimBtn.classList.remove('opacity-50', 'cursor-not-allowed', 'bg-[#2a2a2a]', 'text-white');
            playAnimBtn.classList.add('bg-[#00daf3]', 'text-[#0e0e0e]', 'hover:bg-white');
        } else {
            playAnimBtn.classList.add('opacity-50', 'cursor-not-allowed', 'bg-[#2a2a2a]', 'text-white');
            playAnimBtn.classList.remove('bg-[#00daf3]', 'text-[#0e0e0e]', 'hover:bg-white');
        }
    }

    saveFrameBtn.addEventListener('click', () => {
        if(customFramesB64.length >= 20) { alert("Max frames reached (20)"); return; }
        customFramesB64.push(encodeFrameToBase64());
        updateAnimUI();
    });

    clearAnimBtn.addEventListener('click', () => { customFramesB64 = []; updateAnimUI(); });

    playAnimBtn.addEventListener('click', () => {
        if (customFramesB64.length === 0) return;
        const delay = parseInt(animDelayInput.value) || 200;
        lastSentBuffer = ""; // Reset buffer block
        fetch('/anim', { method: 'POST', body: `ANIM:${delay}:${customFramesB64.join(',')}` }).catch(err => console.error(err));
    });

    // --- FULL STATIC GALLERY (52 Entries) ---
    const galleryPresets = {
        '0': [0x3c,0x42,0x42,0x42,0x42,0x42,0x42,0x3c], '1': [0x18,0x28,0x08,0x08,0x08,0x08,0x08,0x3e],
        '2': [0x3c,0x42,0x02,0x0c,0x30,0x40,0x40,0x7e], '3': [0x3c,0x42,0x02,0x1c,0x02,0x02,0x42,0x3c],
        '4': [0x08,0x18,0x28,0x48,0x7e,0x08,0x08,0x08], '5': [0x7e,0x40,0x40,0x7c,0x02,0x02,0x42,0x3c],
        '6': [0x3c,0x40,0x40,0x7c,0x42,0x42,0x42,0x3c], '7': [0x7e,0x02,0x04,0x08,0x10,0x20,0x20,0x20],
        '8': [0x3c,0x42,0x42,0x3c,0x42,0x42,0x42,0x3c], '9': [0x3c,0x42,0x42,0x42,0x3e,0x02,0x02,0x3c],
        'A': [0x18,0x24,0x42,0x42,0x7e,0x42,0x42,0x42], 'B': [0x7c,0x42,0x42,0x7c,0x42,0x42,0x42,0x7c],
        'C': [0x3c,0x42,0x40,0x40,0x40,0x40,0x42,0x3c], 'D': [0x78,0x44,0x42,0x42,0x42,0x42,0x44,0x78],
        'E': [0x7e,0x40,0x40,0x7c,0x40,0x40,0x40,0x7e], 'F': [0x7e,0x40,0x40,0x7c,0x40,0x40,0x40,0x40],
        'G': [0x3c,0x42,0x40,0x40,0x4e,0x42,0x42,0x3c], 'H': [0x42,0x42,0x42,0x7e,0x42,0x42,0x42,0x42],
        'I': [0x3e,0x08,0x08,0x08,0x08,0x08,0x08,0x3e], 'J': [0x0e,0x04,0x04,0x04,0x04,0x04,0x44,0x38],
        'K': [0x44,0x48,0x50,0x60,0x50,0x48,0x44,0x42], 'L': [0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7e],
        'M': [0x42,0x66,0x5a,0x42,0x42,0x42,0x42,0x42], 'N': [0x42,0x62,0x52,0x4a,0x46,0x42,0x42,0x42],
        'O': [0x3c,0x42,0x42,0x42,0x42,0x42,0x42,0x3c], 'P': [0x7c,0x42,0x42,0x7c,0x40,0x40,0x40,0x40],
        'Q': [0x3c,0x42,0x42,0x42,0x4a,0x44,0x42,0x3d], 'R': [0x7c,0x42,0x42,0x7c,0x48,0x44,0x42,0x42],
        'S': [0x3c,0x42,0x40,0x3c,0x02,0x02,0x42,0x3c], 'T': [0x7e,0x10,0x10,0x10,0x10,0x10,0x10,0x10],
        'U': [0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3c], 'V': [0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00],
        'W': [0x42,0x42,0x42,0x42,0x5a,0x66,0x42,0x00], 'X': [0x42,0x24,0x18,0x18,0x24,0x42,0x42,0x00],
        'Y': [0x42,0x24,0x18,0x10,0x10,0x10,0x10,0x10], 'Z': [0x7e,0x04,0x08,0x10,0x20,0x40,0x40,0x7e],
        '♥': [0x00,0x66,0x99,0x81,0x42,0x24,0x18,0x00], '☺': [0x00,0x24,0x24,0x00,0x42,0x3c,0x00,0x00],
        '☹': [0x00,0x24,0x24,0x00,0x00,0x3c,0x42,0x00], '★': [0x08,0x1c,0x3e,0x7f,0x1c,0x14,0x22,0x00],
        '▲': [0x08,0x14,0x22,0x41,0x7f,0x00,0x00,0x00], '▼': [0x7f,0x41,0x22,0x14,0x08,0x00,0x00,0x00],
        '✔': [0x00,0x02,0x04,0x88,0x50,0x20,0x00,0x00], '✖': [0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81]
    };

    const modalGalleryContainer = document.getElementById('modal-gallery-container');
    const galleryModal = document.getElementById('gallery-modal');
    document.getElementById('open-gallery-btn').addEventListener('click', () => galleryModal.classList.replace('hidden', 'flex'));
    document.getElementById('close-gallery-btn').addEventListener('click', () => galleryModal.classList.replace('flex', 'hidden'));
    
    Object.keys(galleryPresets).forEach(key => {
        const btn = document.createElement('button');
        btn.className = "w-full aspect-square bg-[#2a2a2a] text-white border border-[#474747] font-bold rounded hover:bg-[#00daf3] hover:text-[#0e0e0e] hover:border-transparent active:scale-95 transition-all text-sm";
        btn.textContent = key;
        btn.onclick = () => { loadGalleryPreset(key); galleryModal.classList.replace('flex', 'hidden'); };
        modalGalleryContainer.appendChild(btn);
    });

    // --- Unified Brightness Control ---
    function updateBrightness(val) {
        val = Math.max(1, Math.min(255, val));
        brightnessSlider.value = val; briVal.textContent = val;
        if (val > 50 && !hardwareWarningShown) { alert("Hardware warning\nHigh Brightness Level!"); hardwareWarningShown = true; }
    }
    brightnessSlider.addEventListener('input', (e) => updateBrightness(parseInt(e.target.value)));
    briMinusBtn.addEventListener('click', () => updateBrightness(parseInt(brightnessSlider.value) - 1));
    briPlusBtn.addEventListener('click', () => updateBrightness(parseInt(brightnessSlider.value) + 1));
    document.querySelectorAll('.bri-preset').forEach(btn => btn.addEventListener('click', (e) => updateBrightness(parseInt(e.target.dataset.val))));
    document.querySelectorAll('.quick-color').forEach(btn => btn.addEventListener('click', (e) => { colorPicker.value = e.target.dataset.hex; isErasing = false; }));

    colorPicker.addEventListener('change', () => isErasing = false);
    eraserBtn.addEventListener('click', () => isErasing = true);
    invertToggle.addEventListener('change', () => { lastSentBuffer = ""; sendToESP32(); });

    // Grid Init
    for (let i = 0; i < 64; i++) {
        const cell = document.createElement('div');
        cell.className = 'matrix-cell';
        cell.dataset.r = 0; cell.dataset.g = 0; cell.dataset.b = 0;
        grid.appendChild(cell);
    }

    function calculateHardwareRGB() {
        const rgb = { r: parseInt(colorPicker.value.substring(1,3), 16), g: parseInt(colorPicker.value.substring(3,5), 16), b: parseInt(colorPicker.value.substring(5,7), 16) };
        const bri = parseInt(brightnessSlider.value);
        const maxVal = Math.max(rgb.r, rgb.g, rgb.b, 1);
        return { r: Math.round((rgb.r/maxVal)*bri), g: Math.round((rgb.g/maxVal)*bri), b: Math.round((rgb.b/maxVal)*bri), hex: colorPicker.value, opacity: Math.max(0.15, bri/255) };
    }

    function paintCell(cell) {
        if (!cell) return;
        if (isErasing) { cell.dataset.r=0; cell.dataset.g=0; cell.dataset.b=0; cell.style.backgroundColor='#000'; cell.style.opacity=1; return; }
        const hw = calculateHardwareRGB();
        cell.dataset.r=hw.r; cell.dataset.g=hw.g; cell.dataset.b=hw.b; cell.style.backgroundColor=hw.hex; cell.style.opacity=hw.opacity;
    }

    function loadGalleryPreset(key) {
        const bitmap = galleryPresets[key];
        const cells = Array.from(document.querySelectorAll('.matrix-cell'));
        const hw = calculateHardwareRGB();
        for (let r = 0; r < 8; r++) {
            for (let c = 0; c < 8; c++) {
                let cell = cells[r * 8 + c];
                if ((bitmap[r] >> (7 - c)) & 1) { cell.dataset.r=hw.r; cell.dataset.g=hw.g; cell.dataset.b=hw.b; cell.style.backgroundColor=hw.hex; cell.style.opacity=hw.opacity; } 
                else { cell.dataset.r=0; cell.dataset.g=0; cell.dataset.b=0; cell.style.backgroundColor='#000'; cell.style.opacity=1; }
            }
        }
        lastSentBuffer = "";
        sendToESP32();
    }

    grid.addEventListener('mousedown', (e) => { isDrawing = true; if(e.target.classList.contains('matrix-cell')) paintCell(e.target); });
    grid.addEventListener('mouseover', (e) => { if (isDrawing && e.target.classList.contains('matrix-cell')) paintCell(e.target); });
    window.addEventListener('mouseup', () => { if (isDrawing) { isDrawing = false; sendToESP32(); } });
    grid.addEventListener('touchstart', (e) => { isDrawing = true; e.preventDefault(); handleTouch(e); }, { passive: false });
    grid.addEventListener('touchmove', (e) => { if (!isDrawing) return; e.preventDefault(); handleTouch(e); }, { passive: false });
    window.addEventListener('touchend', () => { if (isDrawing) { isDrawing = false; sendToESP32(); } });

    function handleTouch(e) {
        const element = document.elementFromPoint(e.touches[0].clientX, e.touches[0].clientY);
        if (element && element.classList.contains('matrix-cell')) paintCell(element);
    }

    // THE FIX: Resetting lastSentBuffer so a clear ALWAYS overrides a running animation
    document.getElementById('clear-btn').addEventListener('click', () => {
        document.querySelectorAll('.matrix-cell').forEach(cell => { cell.dataset.r=0; cell.dataset.g=0; cell.dataset.b=0; cell.style.backgroundColor='#000'; cell.style.opacity=1; });
        lastSentBuffer = ""; 
        sendToESP32(); 
    });

    function getRawMatrixData() {
        const cells = Array.from(document.querySelectorAll('.matrix-cell'));
        let grid2D = [];
        for (let i = 0; i < 8; i++) grid2D.push(cells.slice(i * 8, i * 8 + 8).map(c => [parseInt(c.dataset.r)||0, parseInt(c.dataset.g)||0, parseInt(c.dataset.b)||0]));
        let outputGrid = invertToggle.checked ? grid2D.reverse().map(row => row.reverse()) : grid2D;
        const flatBuffer = [];
        outputGrid.forEach(row => row.forEach(rgb => flatBuffer.push(...rgb)));
        return flatBuffer;
    }
    
    function encodeFrameToBase64() {
        const data = getRawMatrixData();
        const bytes = new Uint8Array(data);
        let binary = '';
        for (let i = 0; i < bytes.byteLength; i++) binary += String.fromCharCode(bytes[i]);
        return window.btoa(binary);
    }

    function sendToESP32() {
        const b64Payload = encodeFrameToBase64();
        if (b64Payload === lastSentBuffer) return;
        lastSentBuffer = b64Payload;
        fetch('/draw', { method: 'POST', body: b64Payload }).catch(err => console.error(err));
    }

    // Desktop Drag-to-Scroll for Galleries
    document.querySelectorAll('.gallery-drag').forEach(container => {
        let isDown = false; let startX; let scrollLeft;
        container.addEventListener('mousedown', (e) => { isDown = true; startX = e.pageX - container.offsetLeft; scrollLeft = container.scrollLeft; });
        container.addEventListener('mouseleave', () => isDown = false);
        container.addEventListener('mouseup', () => isDown = false);
        container.addEventListener('mousemove', (e) => {
            if (!isDown) return; e.preventDefault();
            const x = e.pageX - container.offsetLeft;
            container.scrollLeft = scrollLeft - (x - startX) * 2;
        });
    });
</script>
</body>
</html>
)rawliteral";

#endif // HTML_VIEWS_H