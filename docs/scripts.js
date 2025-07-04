fetch('index.md')
      .then(response => response.text())
      .then(text => {
        const contentDiv = document.getElementById('content');
        contentDiv.innerHTML = marked.parse(text);

        const tocDiv = document.getElementById('table-of-contents');
        const headers = contentDiv.querySelectorAll('h1, h2, h3');
        let tocHtml = '<h2>Table of Contents</h2><ul>';
        let currentH1 = null;
        let currentH2 = null;

        headers.forEach((header, index) => {
          const id = header.id || `section-${index}`;
          header.id = id;

          const link = `<a href="#${id}">${header.textContent}</a>`;

          if (header.tagName === 'H1') {
            if (currentH1) {
              if (currentH2) {
                tocHtml += '</ul></li>';
                currentH2 = null;
              }
              tocHtml += '</ul></li>';
            }
            tocHtml += `<li>${link}<ul>`;
            currentH1 = header;
            currentH2 = null;
          } else if (header.tagName === 'H2') {
            if (currentH2) {
              tocHtml += '</ul></li>';
            }
            tocHtml += `<li>${link}<ul>`;
            currentH2 = header;
          } else if (header.tagName === 'H3') {
            tocHtml += `<li>${link}</li>`;
          }
        });

        if (currentH2) {
          tocHtml += '</ul></li>';
        }
        if (currentH1) {
          tocHtml += '</ul></li>';
        }
        tocHtml += '</ul>';
        tocDiv.innerHTML = tocHtml;

        // Smooth scrolling
        document.querySelectorAll('#table-of-contents a').forEach(anchor => {
          anchor.addEventListener('click', function (e) {
            e.preventDefault();
            document.querySelector(this.getAttribute('href')).scrollIntoView({
              behavior: 'smooth'
            });
            // Collapse sidebar after clicking a link
            sidebar.classList.add('collapsed');
            body.classList.add('sidebar-collapsed');
          });
        });

        // Sidebar toggle logic
        const sidebarToggle = document.getElementById('sidebar-toggle');
        const sidebar = document.getElementById('sidebar');
        const body = document.body;

        // Set initial state to collapsed
        sidebar.classList.add('collapsed');
        body.classList.add('sidebar-collapsed');

        sidebarToggle.addEventListener('click', () => {
          sidebar.classList.toggle('collapsed');
          body.classList.toggle('sidebar-collapsed');
        });

        // Scroll to top when home button is clicked
        const homeButton = document.getElementById('home-button');
        homeButton.addEventListener('click', () => {
          window.scrollTo({ top: 0, behavior: 'smooth' });
        });

        // Theme toggle logic
        const themeToggle = document.getElementById('theme-toggle');
        const themeIconLight = document.getElementById('theme-icon-light');
        const themeIconDark = document.getElementById('theme-icon-dark');
        const starIconLight = document.getElementById('star-button-light');
        const starIconDark = document.getElementById('star-button-dark');

        const setTheme = (theme) => {
          body.setAttribute('data-theme', theme);
          localStorage.setItem('theme', theme);
          if (theme === 'dark') {
            starIconLight.style.display = 'none';
            starIconDark.style.display = 'inline-block';
            themeIconLight.style.display = 'none';
            themeIconDark.style.display = 'inline-block';
          } else {
            starIconLight.style.display = 'inline-block';
            starIconDark.style.display = 'none';
            themeIconLight.style.display = 'inline-block';
            themeIconDark.style.display = 'none';
          }
          sidebar.classList.add('collapsed');
          body.classList.add('sidebar-collapsed');
        };

        const toggleTheme = () => {
          const currentTheme = body.getAttribute('data-theme');
          const newTheme = currentTheme === 'dark' ? 'light' : 'dark';
          setTheme(newTheme);
        };

        // Set initial theme based on localStorage or system preference
        const savedTheme = localStorage.getItem('theme');
        if (savedTheme) {
          setTheme(savedTheme);
        } else if (window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches) {
          setTheme('dark');
        } else {
          setTheme('light');
        }

        themeToggle.addEventListener('click', toggleTheme);
      });