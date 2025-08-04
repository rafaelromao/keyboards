document.addEventListener('DOMContentLoaded', () => {
  const fetchAndRender = (lang) => {
    let file = 'index.md';
    if (lang === 'pt') {
      file = 'index.pt.md';
    }

    fetch(file)
      .then(response => response.text())
      .then(text => {
        const contentDiv = document.getElementById('content');
        contentDiv.innerHTML = marked.parse(text);

        // Dynamically set the document title from the first heading of the markdown
        const firstHeading = contentDiv.querySelector('h1');
        if (firstHeading) {
          document.title = firstHeading.textContent;
        }

        const tocDiv = document.getElementById('table-of-contents');
        const headers = contentDiv.querySelectorAll('h1, h2, h3');
        let tocHtml = '<ul>';
        let currentH1 = null;
        let currentH2 = null;

        const slugify = (text) =>
          text
            .toLowerCase()
            .trim()
            .replace(/[\s_]+/g, '-')
            .replace(/[^\w\-]+/g, '');

        headers.forEach((header) => {
          const id = slugify(header.textContent);
          header.id = id;

          header.style.cursor = 'pointer';
          header.addEventListener('click', () => {
            const targetId = `#${id}`;
            history.pushState(null, null, targetId);
            scrollToTarget(targetId);
            sidebar.classList.add('collapsed');
            body.classList.add('sidebar-collapsed');
          });

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

        const scrollToTarget = (targetId, smooth = true) => {
          const targetElement = document.querySelector(targetId);
          if (targetElement) {
            const headerOffset = document.getElementById('banner').offsetHeight;
            const elementPosition = targetElement.getBoundingClientRect().top;
            const offsetPosition = elementPosition + window.pageYOffset - headerOffset;
            window.scrollTo({
              top: offsetPosition,
              behavior: smooth ? 'smooth' : 'auto'
            });
          }
        }

        // Smooth scrolling
        document.querySelectorAll('#table-of-contents a').forEach(anchor => {
          anchor.addEventListener('click', function (e) {
            e.preventDefault();
            const targetId = this.getAttribute('href');
            history.pushState(null, null, targetId);
            scrollToTarget(targetId);

            // Collapse sidebar after clicking a link
            sidebar.classList.add('collapsed');
            body.classList.add('sidebar-collapsed');
          });
        });

        // Scroll to section if URL has hash
        if (window.location.hash) {
          setTimeout(() => scrollToTarget(window.location.hash, false), 100);
        }
      });
  };

  const languageToggle = document.getElementById('language-toggle');
  const langEn = document.getElementById('lang-en');
  const langPt = document.getElementById('lang-pt');

  const setLanguage = (lang) => {
    localStorage.setItem('language', lang);
    if (lang === 'pt') {
      langEn.classList.remove('active');
      langPt.classList.add('active');
    } else {
      langPt.classList.remove('active');
      langEn.classList.add('active');
    }
    const url = new URL(window.location);
    url.searchParams.set('lang', lang);
    history.pushState({}, '', url);
    fetchAndRender(lang);
  };

  const toggleLanguage = () => {
    const urlParams = new URLSearchParams(window.location.search);
    const currentLang = urlParams.get('lang') || localStorage.getItem('language') || 'en';
    const newLang = currentLang === 'en' ? 'pt' : 'en';
    setLanguage(newLang);
  };

  // Set initial language based on localStorage or browser settings
  const urlParams = new URLSearchParams(window.location.search);
  const urlLang = urlParams.get('lang');
  const savedLang = localStorage.getItem('language');
  const browserLang = navigator.language.split('-')[0];

  if (urlLang) {
    setLanguage(urlLang);
  } else if (savedLang) {
    setLanguage(savedLang);
  } else if (browserLang === 'pt') {
    setLanguage('pt');
  } else {
    setLanguage('en');
  }

  languageToggle.addEventListener('click', toggleLanguage);

  // Sidebar toggle logic
  const sidebarToggle = document.getElementById('sidebar-toggle');
  const sidebar = document.getElementById('sidebar');
  const body = document.body;

  // Set initial state to collapsed
  sidebar.classList.add('collapsed');
  body.classList.add('sidebar-collapsed');

  sidebarToggle.addEventListener('click', (event) => {
    event.stopPropagation();
    sidebar.classList.toggle('collapsed');
    body.classList.toggle('sidebar-collapsed');
  });

  document.addEventListener('click', (event) => {
    const isClickInsideSidebar = sidebar.contains(event.target);
    const isSidebarToggle = sidebarToggle.contains(event.target);

    if (!isClickInsideSidebar && !isSidebarToggle && !sidebar.classList.contains('collapsed')) {
      sidebar.classList.add('collapsed');
      body.classList.add('sidebar-collapsed');
    }
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

  // Handle scrolling to update the banner
  window.addEventListener('scroll', () => {
    const banner = document.getElementById('banner');
    const mainContent = document.getElementById('main-content');
    const scrollPosition = window.scrollY;

    if (scrollPosition > 50) {
      banner.classList.add('scrolled');
      mainContent.classList.add('scrolled');
    } else {
      banner.classList.remove('scrolled');
      mainContent.classList.remove('scrolled');
    }
  });
});