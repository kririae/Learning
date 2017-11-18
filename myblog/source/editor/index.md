---
title: editor
id: 191
comment: false
date: 2017-11-04 23:46:54
---

<script type="text/javascript" src="http://yuyuko.cc/package/min/vs/loader.js"></script>

<script>
    require.config({ paths: { 'vs': 'http://yuyuko.cc/package/min/vs' }});

    // Before loading vs/editor/editor.main, define a global MonacoEnvironment that overwrites
    // the default worker url location (used when creating WebWorkers). The problem here is that
    // HTML5 does not allow cross-domain web workers, so we need to proxy the instantiation of
    // a web worker through a same-domain script
    window.MonacoEnvironment = {
        getWorkerUrl: function(workerId, label) {
            return 'monaco-editor-worker-loader-proxy.js';
        }
    };

    require(["vs/editor/editor.main"], function () {
        wait...
    });
</script>